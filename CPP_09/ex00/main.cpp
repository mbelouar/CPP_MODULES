#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    // Ensure that a file is provided as an argument
    if (argc != 2) {
        std::cerr << "Error: You must provide an input file." << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;

    btcExchange.loadPriceHistory("data.csv");

    btcExchange.processInput(argv[1]);

    return 0;
}
