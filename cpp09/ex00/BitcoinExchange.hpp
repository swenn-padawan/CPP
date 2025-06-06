#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string &filename);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		BitcoinExchange(const BitcoinExchange &other);
	private:
		std::map<std::string, float> _data;
};
