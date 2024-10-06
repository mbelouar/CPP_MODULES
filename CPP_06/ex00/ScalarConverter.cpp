#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    if (this == &src)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str) {
    size_t start = 0;

    if (str[0] == '+' || str[0] == '-') {
        start = 1;
    }
    if (start == str.size()) {
        return false;
    }
    // Check if all characters from 'start' onwards are digits
    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    size_t start = 0;
    bool hasDigits = false;
    bool hasDecimal = false;

    // check if str end with a 'f' or 'F'
    if ((str.back() != 'f' && str.back() != 'F')) {
        return false;
    }

    if (str[0] == '+' || str[0] == '-') {
        start++;
    }

    for (size_t i = start; i < str.size() - 1; ++i) {
        char c = str[i];
        if (std::isdigit(c)) {
            hasDigits = true;
        } else if (c == '.') {
            if (hasDecimal) return false; // More than one decimal point
            hasDecimal = true;
        } else {
            return false; // Invalid character
        }
    }
    return hasDigits; // Must have at least one digit
}

bool ScalarConverter::isDouble(const std::string& str) {
    size_t start = 0;
    bool hasDigits = false;
    bool hasDecimal = false;

    if (str[0] == '+' || str[0] == '-') {
        start++;
    }

    for (size_t i = start; i < str.size(); ++i) {
        char c = str[i];
        if (std::isdigit(c)) {
            hasDigits = true;
        } else if (c == '.') {
            if (hasDecimal) return false; // More than one decimal point
            hasDecimal = true;
        } else {
            return false; // Invalid character
        }
    }
    return hasDigits; // Must have at least one digit
}

void ScalarConverter::CharConversion(const std::string& str) {
    char c = str[0];
    std::cout << "==== CHAR ====\n";
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::IntConversion(const std::string& str) {
    std::cout << "==== INT ====\n";
    int i = std::stoi(str);
    if (i < 32 || i > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << static_cast<float>(i) << "f\n";
    std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::FloatConversion(const std::string& str) {
    float f = std::stof(str);
    std::cout << "==== FLOAT ====\n";
    if (f < 32 || f > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void ScalarConverter::DoubleConversion(const std::string& str) {
    double d = std::stod(str);
    std::cout << "==== DOUBLE ====\n";
    // std::cout << "d = " << d <<std::endl;
    if (d < 32 || d > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    std::cout << "int: " << static_cast<int>(d) << "\n";
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}

void ScalarConverter::NanConversion() {
    std::cout << "==== NAN || NANF ====\n";
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: nanf\n";
    std::cout << "double: nan\n";
}

void ScalarConverter::PlusInfConversion() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: +inff\n";
    std::cout << "double: +inf\n";
}

void ScalarConverter::MinusInfConversion() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: -inff\n";
    std::cout << "double: -inf\n";
}

void ScalarConverter::convert(const std::string& str) {
    if (str == "nan" || str == "nanf") {
        NanConversion();
    } else if (str == "+inff" || str == "+inf") {
        PlusInfConversion();
    } else if (str == "-inff" || str == "-inf") {
        MinusInfConversion();
    } else if (isChar(str)) {
        CharConversion(str);
    } else if (isInt(str)) {
        IntConversion(str);
    } else if (isFloat(str)) {
        FloatConversion(str);
    } else if (isDouble(str)) {
        DoubleConversion(str);
    } else {
        std::cout << "==== OTHER ====\n";
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

