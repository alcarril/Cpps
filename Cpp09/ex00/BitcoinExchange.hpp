

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <algorithm>
#include <exception>
#include <map>


class BitcoinExchange
{
	private:
		std::fstream FbitcoinRates;
		std::fstream FbitcoinPOT;
		std::string PriceOvertimeName;
		std::map<std::string, double> BtcRates;

		bool checkDatesFormat(std::string & date) const ;
		double CheckValuesCsv(std::string & value) const;
		double CheckValuesPOT(std::string & value) const;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		BitcoinExchange(const BitcoinExchange& copy);

		BitcoinExchange(const std::string& imputFile);
		std::map<std::string, double> getBtcRates(void) const ;
		void setInput(const std::string & imputFile);

		void loadDBdataRates(void); 
		void PrintExchangePOT(void); 

} ;

#endif
