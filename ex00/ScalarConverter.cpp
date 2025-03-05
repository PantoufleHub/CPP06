#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define DIGITS "0123456789"
#define F_ALLOWED "0123456789f.-"
#define D_ALLOWED "0123456789.-"

int countOccurences(std::string str, char c)
{
	int count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

bool isChar(std::string str) {

	return (str.size() == 3 
			&& str[0] == '\''
			&& str[2] == '\'');
}

bool isInt(std::string str) {
	size_t minus_pos = str.find('-');

	if (minus_pos != std::string::npos && minus_pos != 0)
    return (0);

	if (str.find_first_not_of(
        DIGITS,
		minus_pos == std::string::npos ? 0 : 1)
		!= std::string::npos)
		return (0);
	return (1);
}

bool isFloat(std::string str)
{
	size_t minus_pos = str.find('-');
	if (minus_pos != std::string::npos && minus_pos != 0)
    	return 0;
	if (countOccurences(str, '-') > 1)
		return 0;

	size_t f_pos = str.find('f');
	if (f_pos == std::string::npos || f_pos != str.length() -1)
    	return 0;
	if (countOccurences(str, 'f') > 1)
		return 0;
	
	size_t dot_pos = str.find('.');
	if (dot_pos == std::string::npos)
    	return 0;
	if (countOccurences(str, '.') > 1)
		return 0;

	size_t num_pos = str.find_first_of(DIGITS, 0);
	if (num_pos == std::string::npos)
		return 0;

	size_t other_pos = str.find_first_not_of(F_ALLOWED);
	if (other_pos != std::string::npos)
		return 0;

	return 1;
}

bool isDouble(std::string str)
{
	size_t minus_pos = str.find('-');
	if (minus_pos != std::string::npos && minus_pos != 0)
    	return 0;
	if (countOccurences(str, '-') > 1)
		return 0;
	
	size_t dot_pos = str.find('.');
	if (dot_pos == std::string::npos)
    	return 0;
	if (countOccurences(str, '.') > 1)
		return 0;

	size_t num_pos = str.find_first_of(DIGITS, 0);
	if (num_pos == std::string::npos)
		return 0;

	size_t other_pos = str.find_first_not_of(D_ALLOWED);
	if (other_pos != std::string::npos)
		return 0;

	return 1;
}

bool isInfinite(std::string str)
{
	if (str == "inf" || str == "inff"
		|| str == "-inf" || str == "-inff"
		|| str == "nan" || str == "nanf")
		return 1;
	return 0;
}

void printChar(char value)
{	
	std::cout << "char  : ";
	if (value >= std::numeric_limits<char>::min()
		&& value <= std::numeric_limits<char>::max())
	{
		char c = value;
		if (isprint(c))
			std::cout << "\'" << c << "\'";
		else
			std::cout << "not printable";
		std::cout << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
		}

void printInt(long int value)
{
	std::cout << "int   : ";
	if (value < std::numeric_limits<int>::min())
		std::cout << "underflow";
	else if (value > std::numeric_limits<int>::max())
		std::cout << "overflow";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

void printFloat(float value)
{
	std::cout << "float : ";
	if (value < -std::numeric_limits<float>::max())
		std::cout << "underflow";
	else if (value > std::numeric_limits<float>::max())
		std::cout << "overflow";
	else
	{
		std::cout << static_cast<float>(value);
		if (value - (double)((int)value) == 0)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;
}

void printDouble(long double value)
{
	std::cout << "double: ";
	if (value < -std::numeric_limits<double>::max())
		std::cout << "underflow";
	else if (value > std::numeric_limits<double>::max())
		std::cout << "overflow";
	else
	{
		std::cout << static_cast<double>(value);
		if (value - (double)((int)value) == 0)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void convertFromChar(std::string str)
{
	std::cout << "Type: char" << std::endl;
	char c = str[1];

	// std::cout << "char  : "	<< ((isprint(num)) ? str : "not printable") << std::endl;
	// std::cout << "int   : "	<< num << std::endl;
	// std::cout << "float : "	<< num << ".0f" << std::endl;
	// std::cout << "double: "	<< num << ".0" << std::endl;

	printChar(c);
	printInt(static_cast<long int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<long double>(c));
}

void convertFromInt(std::string str)
{
	std::cout << "Type: int" << std::endl;
	long int value = atol(str.c_str());
	// std::cout << "Got value: " << long_value << std::endl;

	printChar(static_cast<char>(value));
	printInt(value);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<long double>(value));
}

void convertFromFloat(std::string str)
{
	std::cout << "Type: float" << std::endl;
	float value = atof(str.c_str());
	// std::cout << "Got value: " << long_value << std::endl;

	printChar(static_cast<char>(value));
	printInt(static_cast<long int>(value));
	printFloat(value);
	printDouble(static_cast<long double>(value));
}

void convertFromDouble(std::string str)
{
	std::cout << "Type: double" << std::endl;
	long double value = strtold(str.c_str(), NULL);
	// std::cout << "Got value: " << long_value << std::endl;

	printChar(static_cast<char>(value));
	printInt(static_cast<long int>(value));
	printFloat(static_cast<float>(value));
	printDouble(value);
}

void displayUnknown()
{
	std::cout << "Unknown type" << std::endl;
}

void displayInfinite(std::string str)
{
	std::cout << "char  : impossible"	<< std::endl;
	std::cout << "int   : impossible"	<< std::endl;
	if (str == "inf" || str == "inff")
	{
		std::cout << "float : inff"	<< std::endl;
		std::cout << "double: inf"	<< std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float : -inff"	<< std::endl;
		std::cout << "double: -inf"		<< std::endl;
	}
	else
	{
		std::cout << "float : nanf"	<< std::endl;
		std::cout << "double: nan"	<< std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
	std::cout << " --- Converting [" << str << "] ---" << std::endl;
	if (isChar(str))
		convertFromChar(str);
	else if (isInfinite(str))
		displayInfinite(str);
	else if (isInt(str))
		convertFromInt(str);
	else if (isFloat(str))
		convertFromFloat(str);
	else if (isDouble(str))
		convertFromDouble(str);
	else
		displayUnknown();
}
