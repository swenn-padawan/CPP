#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	//useless cause class is empty
	return (*this);
};

void ScalarConverter::convert(const std::string toConvert){
	std::cout << "Time To Convert" << std::endl;
	if (toConvert.length() == 1){
		if (!std::isprint(toConvert.c_str())){
			std::cout << "Impossible" << std::endl;
			return ;
		}
		if (!std::isdigit(toConvert.c_str()))
	}
		
}
