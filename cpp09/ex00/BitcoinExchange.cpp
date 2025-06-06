#include "BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {*this = other;}

BitcoinExchange::BitcoinExchange(std::string &filename){
	std::ifstream file(filename.c_str());
	if (!file.is_open()){
		std::cerr << "Cannot Open The File\n";
		return ;
	}
	std::string	line;

	std::getline(file, line);
	while (std::getline(file, line)){

	}

}
