#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <string>" << std::endl;
        return 1;
    }
    
    std::string string = argv[1];
    ScalarConverter::convert(string);

    return 0;
}
