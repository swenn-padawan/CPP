#pragma once

#include <iostream>

class ScalarConverter{
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter &operator=(const ScalarConverter &src);

		void	convert(const std::string toConvert);

	private:
		ScalarConverter(){};
};
