

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() { 
	this->loadDBdataRates();
} ;

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	if (this != &other)
		*this = other;
} ;

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		this->BtcRates = copy.BtcRates;
		this->PriceOvertimeName = copy.PriceOvertimeName;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	if (this->FbitcoinRates.is_open())
		this->FbitcoinRates.close();
	if (this->FbitcoinPOT.is_open()) {
		this->FbitcoinPOT.close();
	}
} ;


BitcoinExchange::BitcoinExchange(const std::string& imputFile) : PriceOvertimeName(imputFile) {
	this->loadDBdataRates();
}

std::map<std::string, double> BitcoinExchange::getBtcRates(void) const {
	return this->BtcRates;
}

void BitcoinExchange::setInput(const std::string & imputFile) {
	this->PriceOvertimeName = imputFile;
}



/*
	Comprobaciones de apertura de CSV base de datos
		Se comporueba que el searador de key(date) y value (rate) exista
		Se separa la cadena en dos:
			La key se compiruab que siga el foramto de fecha
			El value se compruba que sea un valor numerico
		Se trata de insertar la el par y si se comprueba is existia o no
*/
void BitcoinExchange::loadDBdataRates(void) {
	std::string rawLine;
	size_t dotPos;
	int line = 0;
	this->FbitcoinRates.open("data.csv", std::ios::in);
	if (this->FbitcoinRates.is_open()) {
		while (std::getline(this->FbitcoinRates, rawLine)) {
			if (line == 0) {
				line++;
				continue;
			}
			dotPos = rawLine.find(",");
			if (dotPos != rawLine.npos) {
				std::string dateK = rawLine.substr(0, dotPos); 
				if (!this->checkDatesFormat(dateK))
					throw std::logic_error("Invalid Date in one line\n");
				std::string value2 = rawLine.substr(dotPos + 1);
				double value = this->CheckValuesCsv(value2);
				std::pair<std::map<std::string, double>::iterator, bool> res = this->BtcRates.insert(std::pair<std::string, double>(dateK, value));
				if (res.second == false)
					throw std::logic_error("Dates can`t be duplicate\n");
			}
			else
				throw std::logic_error("Invalid line format\n");
			rawLine.clear();
		}
	}
	else {
		throw std::runtime_error("File couldn't be open\n");
	}
}

/*
	Comporbaciones de apertita POT imput
		Que el archivo se abra como debe sino excepcio
		Una vez abierto de cada linea en el bucle un bloque try y cath para:
			- Si hay mas escaios por lo que lo s lexemas son mas de los normales
			- Si el seprador no es el segundo
			- Si las fechas estan mal por no seguir el formato
			MISMO TIPO DE ERROR
			- Si el valor es menor que cero error de value
			- Si el valor es mayor que mil erro too large numeber
			- Si el valor desborda o no tiene nuemros errrosres personlizados (ver hoja de corrrecion)
*/
void BitcoinExchange::PrintExchangePOT(void) {
	std::string rawLine;
	std::stringstream s;
	std::string lex;
	int control = 0;
	int control2 = 0;
	if (this->PriceOvertimeName.empty())
		throw std::logic_error("Loading Prices Over Time Csv Error: No file selected\n");
	this->FbitcoinPOT.open(this->PriceOvertimeName.c_str(), std::ios::in);
	if (this->FbitcoinPOT.is_open()) {
		while (std::getline(this->FbitcoinPOT, rawLine)) {
			if (control == 0) {
				if (rawLine.empty()) 
					control2 = 1;
				control++;
				continue;
			}
			try {
				std::stringstream s(rawLine);
				std::string lex[3];
				int i = 0;
				while (s >> lex[i]) {i++;}
				if (i != 3 || lex[1] != "|") {
					std::string msg = "Error: bad input => " + rawLine + "\n";
					throw std::logic_error(msg);
				}
				this->checkDatesFormat(lex[0]);
				double value = this->CheckValuesPOT(lex[2]);
				std::map<std::string, double>::iterator it = this->BtcRates.find(lex[0]);
				if (it == this->BtcRates.end()) {
					it = this->BtcRates.lower_bound(lex[0]);
					if (it != this->BtcRates.begin()) {
						--it;
					}
				}
				std::cout << lex[0] << " => " << value << " = "<<(value * it->second) << std::endl;
			} catch (std::exception& e) {
				std::cerr << e.what();
			}
			control++;
			rawLine.clear();
		}
		if (control2 == 1)
			throw std::logic_error("Loading Prices Over Time Csv Error: Empty file\n");
	}
	else {
		throw std::runtime_error("Loading DataBase POT Error: File couldn't be open\n");
	}
	this->FbitcoinPOT.clear();
	this->FbitcoinPOT.seekg(0, std::ios::beg);
}

/*
	Comprobaciones de formato de fecha
		Que la longitud sea 10
		Que el separador sea el guion y este en la posicion correcta
		Que los caracteres sean numeros o guiones en las posiciones correctas
		Que las fechas no sean futuras (faltaria)
*/
bool BitcoinExchange::checkDatesFormat(std::string& date) const {

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++) {
		if (!isdigit(date[i]) && i != 4 && i != 7) {
			return false;
		}
	}

	//Comprobacion de formatos de fechas validas -> Funciona
	std::string lex[3];
	std::stringstream dateTemp(date);
	std::string token;
	int i = 0;
	while (i < 3 && std::getline(dateTemp, token, '-')) {
		lex[i] = token;
		//Igual se necesita un otcker.clear()
		i++;
	}
	if (lex[1] == "02" && ((std::atoi(lex[0].c_str()) % 4 == 0 && lex[2] > "29") || lex[2] > "28")) {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if (lex[0] == "0000" || lex[1] == "00" || lex[2] == "00") {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if (lex[1] > "12") {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if ((lex[1] == "04" || lex[1] == "06" || lex[1] == "09" || lex[1] == "11") && lex[2] > "30") {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}

	//compbacion de que no esmos poniendo una fecha a futuro -> Fucniona
	static bool control;
	static std::string currentDateString;
	if (control == false) {
		std::time_t t = std::time(NULL);
		std::tm* now = std::localtime(&t);
		control = true;
		static std::stringstream currentDate;
		currentDate << now->tm_year + 1900 << "-" << now->tm_mon + 1 << "-" << now->tm_mday;
		currentDate >> currentDateString;
	}
	if (date > currentDateString) {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	return true;
}

double BitcoinExchange::CheckValuesPOT(std::string & value) const {
	char *input = const_cast<char *>(value.c_str());
	if (*input == '.' && *(input + 1) != '\0')
		throw std::logic_error("Error: No numeric value\n");
	char *endString;
	errno = 0;
	double valid = strtod(input, &endString);
	if (errno == ERANGE)
		throw std::logic_error("Error: Overflow\n");
	if (std::isnan(valid) || std::isinf(valid)) {
		throw std::logic_error("Error: Not a number\n");
	}
	if (*endString != '\0') {
		if (*endString == 'f') {
			if (*(endString + 1) != '\0')
				throw std::logic_error("Error: No numeric value\n");
			size_t pos = value.find(".");
			if (pos == std::string::npos)
				throw std::logic_error("Error: No numeric value\n");
		}
	}
	if (valid < 0) {
		throw std::logic_error("Error: not a positive number.\n");
	}
	if (valid > 1000) {
		throw std::logic_error("Error: too large a number.\n");
	}
	return valid;
}

double BitcoinExchange::CheckValuesCsv(std::string & value) const {
	char *input = const_cast<char *>(value.c_str());
	if (*input == '.' && *(input + 1) != '\0')
		throw std::logic_error("Loading DataBase Error: No numeric value in one line\n");
	char *endString;
	errno = 0;
	double valid = strtod(input, &endString);
	if (errno == ERANGE)
		throw std::logic_error("Loading DataBase Error: Overflow value in one line\n");
	if (std::isnan(valid) || std::isinf(valid)) {
		throw std::logic_error("Loading DataBase Error: Not a number in one line\n");
	}
	if (*endString != '\0') {
		if (*endString == 'f') {
			if (*(endString + 1) != '\0')
				throw std::logic_error("Loading DataBase Error: No numeric value in one line\n");
			size_t pos = value.find(".");
			if (pos == std::string::npos)
				throw std::logic_error("Loading DataBase Error: No numeric value in one line\n");
		}
	}
	return valid;
}
