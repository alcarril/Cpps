
#include "BitcoinExchange.hpp"

int main(int argz, char **argv)
{
	if (argz > 2) {
		std::cerr << "This program needs only one argument [./btc <filepath>]\n";
		return 1;
	}
	if (argz < 2) {
		std::cerr << "Error: could not open file\n";
		return 1;
	}
	try {
		BitcoinExchange Exchage;
		Exchage.setInput(std::string(argv[1]));
		Exchage.PrintExchangePOT();
	} catch (std::exception& e) {
		std::cerr << "Loading DataBase Error: " << e.what();
	}
	return (0);
}