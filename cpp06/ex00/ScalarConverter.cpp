#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cctype>

ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

static bool isCharLiteral(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

static bool isIntLiteral(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}

static bool isFloatLiteral(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool isDoubleLiteral(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

static bool isDisplayableChar(int value) {
    return value >= 32 && value <= 126;
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    if (isCharLiteral(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (isIntLiteral(literal)) {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        int i = static_cast<int>(l);
        if (isDisplayableChar(i))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        int i = static_cast<int>(f);
        if (f != f || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "char: impossible" << std::endl;
        else if (isDisplayableChar(i))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (f != f || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        int i = static_cast<int>(d);
        if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "char: impossible" << std::endl;
        else if (isDisplayableChar(i))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;

        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

