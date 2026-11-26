
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
		return 1;
	}
	return 0;
}

/*
	Possible failures, parsing error handling:
		Invalid dates:
			Incorrect year-month-day format
			Future dates
			Months with more days than allowed
			February
		input.txt format (prices over time):
			Missing three fields separated by spaces
			Missing a header on the first line
			Empty file
			Header-only file
			Field 1 (date): does not follow the date format rules
			Field 2 (separator): is another character
			Field 3 (value):
				Is not a number or contains invalid characters
				Overflows
				Can be a float
				Can be a decimal
				Is negative or greater than 1000
		data.csv format (Bitcoin price):
			Incorrect date-comma-value format
			Filename must be data.csv
			Missing the header on the first line
			Empty file
			Header-only file
			Field 1 (date): does not follow the date rules
			Field 2 (value):
				Is not a number or contains invalid characters
				Overflows
				Can be a float
				Can be a decimal
		Matching prices over time with data.csv:
			When the value for a date is not found
			Do not keep the previous value
			The previous value must be the latest value in the database
			There may be no previous value if the date is earlier than the first date in the database
*/