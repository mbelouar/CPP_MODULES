#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
    private:
        std::string input;
    public:
        ScalarConverter();
        ScalarConverter(std::string input);
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();

        void convert();
};

#endif 