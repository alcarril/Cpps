

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
	Database CSV opening checks:
		Check that the separator between key (date) and value (rate) exists
		Split the string into two parts:
			Check that the key follows the date format
			Check that the value is numeric
		Try to insert the pair and check whether it already exists
*/
void BitcoinExchange::loadDBdataRates(void) {
	std::string rawLine;
	size_t dotPos;
	int line = 0;
	this->FbitcoinRates.open("data.csv", std::ios::in);
	if (this->FbitcoinRates.is_open()) {
		while (std::getline(this->FbitcoinRates, rawLine)) {
			if (line == 0) {
				if (rawLine != "date,exchange_rate")
					throw std::logic_error("Invalid data.csv header\n");
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
		if (line == 0)
			throw std::logic_error("Loading DataBase Error: Empty data.csv file\n");// No header is present
		if (this->BtcRates.empty())
			throw std::logic_error("Loading DataBase Error: data.csv has no data rows\n");// Only the header is present
	}
	else {
		throw std::runtime_error("File couldn't be open\n");
	}
}

/*
	Prices-over-time input opening checks:
		The file must open correctly; otherwise, throw an exception
		Once opened, use a try/catch block for each line in the loop:
			- Extra spaces causing too many tokens
			- The separator is not the second token
			- The date does not follow the required format
			SAME ERROR TYPE
			- Value less than zero: value error
			- Value greater than one thousand: too-large-number error
			- Overflow or non-numeric value: custom errors (see the correction sheet)
*/
void BitcoinExchange::PrintExchangePOT(void) {
	std::string rawLine;
	int line = 0;
	bool hasDataRows = false;
	if (this->PriceOvertimeName.empty())
		throw std::logic_error("Loading Prices Over Time Csv Error: No file selected\n");
	this->FbitcoinPOT.open(this->PriceOvertimeName.c_str(), std::ios::in);
	if (this->FbitcoinPOT.is_open()) {
		while (std::getline(this->FbitcoinPOT, rawLine)) {
			if (line == 0) {
				if (rawLine != "date | value")
					throw std::logic_error("Loading Prices Over Time Error: Invalid input header\n");
				line++;
				continue;
			}
			hasDataRows = true;
			try {
				std::stringstream s(rawLine);
				std::string lex[3];
				int i = 0;
				while (s >> lex[i]) {i++;}
				if (i != 3 || lex[1] != "|") {
					std::string msg = "Error: bad input => " + rawLine + "\n";
					throw std::logic_error(msg);
				}
				if (!this->checkDatesFormat(lex[0])) {
					std::string msg = "Error: bad input => " + rawLine + "\n";
					throw std::logic_error(msg);
				}
				double value = this->CheckValuesPOT(lex[2]);
				std::map<std::string, double>::iterator it = this->BtcRates.find(lex[0]);
				if (it == this->BtcRates.end()) {
					it = this->BtcRates.lower_bound(lex[0]);
					if (it == this->BtcRates.end()) { // Date is later than the latest date in the map
						--it;
					} else if (it == this->BtcRates.begin()) { // Date is earlier than the first date in the map
						throw std::logic_error("Error: no earlier exchange rate available\n");
					} else {
						--it;
					}
				}
				std::cout << lex[0] << " => " << value << " = "<<(value * it->second) << std::endl;
			} catch (std::exception& e) {
				std::cerr << e.what();
			}
			rawLine.clear();
		}
		if (line == 0)
			throw std::logic_error("Loading Prices Over Time Error: Empty file, expected header\n");// The file has no header
		if (!hasDataRows)
			throw std::logic_error("Loading Prices Over Time Error: File has no data rows\n");// The file only has a header
	}
	else {
		throw std::runtime_error("Loading DataBase POT Error: File couldn't be open\n");
	}
	this->FbitcoinPOT.clear();
	this->FbitcoinPOT.seekg(0, std::ios::beg);
}

/*
	Date-format checks:
		The length must be 10
		The separator must be a hyphen in the correct position
		Characters must be digits or hyphens in the correct positions
		Dates must not be in the future (missing)
*/
bool BitcoinExchange::checkDatesFormat(std::string& date) const {

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++) {
		if (!isdigit(date[i]) && i != 4 && i != 7) {
			return false;
		}
	}

	// Check valid date formats -> Works
	std::string lex[3];
	std::stringstream dateTemp(date);
	std::string token;
	int i = 0;
	while (i < 3 && std::getline(dateTemp, token, '-')) {
		lex[i] = token;
		// A otcker.clear() call may be needed
		i++;
	}
	if (lex[1] == "02" &&
		((std::atoi(lex[0].c_str()) % 4 == 0 && lex[2] > "29") ||
		(std::atoi(lex[0].c_str()) % 4 != 0 && lex[2] > "28"))) { //feb
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if (lex[0] == "0000" || lex[1] == "00" || lex[2] == "00" || lex[2] > "31") {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if (lex[1] > "12") {
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}
	if ((lex[1] == "04" || lex[1] == "06" || lex[1] == "09" || lex[1] == "11") && lex[2] > "30") { //30 days moths
		std::string msg = "Error: Invalid date format: " + date + "\n";
		throw std::logic_error(msg);
	}

	// Check that we are not using a future date -> Works
	static bool control;
	static std::string currentDateString;
	if (control == false) {
		std::time_t t = std::time(NULL);
		std::tm* now = std::localtime(&t);
		control = true;
		static std::stringstream currentDate;
			currentDate << std::setfill('0')
			<< std::setw(4) << now->tm_year + 1900 << "-"
			<< std::setw(2) << now->tm_mon + 1 << "-"
			<< std::setw(2) << now->tm_mday;
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
		else
			throw std::logic_error("Error: No numeric value\n");
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
		else
			throw std::logic_error("Loading DataBase Error: No numeric value in one line\n");

	}
	return valid;
}
