#pragma once

# define UNUSED(x) ((void)x)

#include <iostream>

class ScalarConverter{
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter &operator=(const ScalarConverter &src);

		static void	convert(const std::string &toConvert);

	private:
		ScalarConverter(){};
};
