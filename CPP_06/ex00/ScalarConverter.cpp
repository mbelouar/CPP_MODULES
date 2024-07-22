#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : input("") {}

ScalarConverter::ScalarConverter(std::string input) : input(input) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : input(src.input) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    if (this != &src)
        input = src.input;
    return *this;
}

ScalarConverter::~ScalarConverter() {}