#include "RPN.hpp"

int main(int argc, char** argv) {
    // Check if there is exactly one argument (the RPN expression)
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    try {
        // Create an RPN calculator object
        RPN rpnCalculator;

        // Calculate the result using the provided expression
        int result = rpnCalculator.calculate(argv[1]);

        // Output the result to the standard output
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        // If an exception occurs, output the error message
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
