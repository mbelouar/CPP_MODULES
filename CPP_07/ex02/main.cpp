#include "Array.hpp"

int main() {

    std::cout << "===> Test with default constructor" << std::endl;

    Array<int>  intArray(5);

    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i;
    }

    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    try {
        intArray[5] = 42;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===> Test with copy constructor" << std::endl;

    Array<int>  intArray2(intArray);

    for (unsigned int i = 0; i < intArray2.size(); i++) {
        std::cout << intArray2[i] << " ";
    }
    std::cout << std::endl;
    
    try {
        intArray2[5] = 42;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===> Test with assignment operator" << std::endl;

    Array<int>  intArray3;

    intArray3 = intArray;

    for (unsigned int i = 0; i < intArray3.size(); i++) {
        std::cout << intArray3[i] << " ";
    }
    std::cout << std::endl;
    
    try {
        intArray3[5] = 42;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===> Test with const Array" << std::endl;
    
    const Array<int> constIntArray(intArray);

    for (unsigned int i = 0; i < constIntArray.size(); i++) {
        std::cout << constIntArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        for (unsigned int i = 0; i < constIntArray.size() + 1; i++) {
            std::cout << constIntArray[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
