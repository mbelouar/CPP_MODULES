#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    
    std::cout << std::endl;
    try {
        std::cout << "-> " << easyfind(v, 0) << std::endl;
        std::cout << "-> " << easyfind(v, 9) << std::endl;
        std::cout << "-> " << easyfind(v, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }
}