#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();

        static void convert(const std::string& str);

        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);

        static void CharConversion(const std::string& str);
        static void IntConversion(const std::string& str);
        static void FloatConversion(const std::string& str);
        static void DoubleConversion(const std::string& str);
        static void NanConversion();
        static void PlusInfConversion();
        static void MinusInfConversion();
};

#endif 