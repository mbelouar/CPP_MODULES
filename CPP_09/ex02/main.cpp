#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // For std::atoi

int main(int argc, char **argv) {
    PmergeMe pmm;

    if (argc > 2) {
        // // Parse command-line arguments and add to containers
        // for (int i = 1; i < argc; ++i) {
        //     int number = std::atoi(argv[i]);
        //     pmm.addNumberToContainers(number);
        // }

        // // Retrieve the vector and list from PmergeMe
        // const std::vector<int>& vec = pmm.getVector();

        // // Print the contents of the vector
        // std::cout << "Vector elements: ";
        // for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        pmm.start(argv);
    } else {
        std::cout << "Usage: ./pmergeMe [number1] [number2] ..." << std::endl;
    }

    return 0;
}