#include "Array.hpp"

int main() {

    Array<int> emptyArray;

    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    try {
        std::cout << emptyArray[0] << std::endl; 
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
