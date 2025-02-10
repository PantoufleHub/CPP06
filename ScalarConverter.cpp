#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

#define DIGITS "123456789"

// ScalarConverter::ScalarConverter(){}

// ScalarConverter::~ScalarConverter(){} 

bool isChar(std::string str) {
	return (str.size() == 3 
			&& str[0] == '\''
			&& str[1] == '\'');
}

bool isInteger(std::string str) {
	int minus_pos = str.find('-');

	if (minus_pos != std::string::npos && minus_pos != 0)
    return (0);

	if (str.find_first_not_of(
        DIGITS,
		minus_pos == std::string::npos ? 0 : 1)
		!= std::string::npos)
		return (0);
	return (1);
}



void ScalarConverter::convert(std::string str)
{
	std::cout << " --- Converting [" << str << "] ---" << std::endl;
	// std::cout << "char: " << convertToChar(str) << std::endl;
	// std::cout << "int: " << convertToInt(str) << std::endl;
	// std::cout << "float: " << convertToFloat(str) << std::endl;
	// std::cout << "double: " << convertToDouble(str) << std::endl;
}
