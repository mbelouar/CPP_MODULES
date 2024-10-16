#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cmath>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> priceHistory;
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        std::string findClosestDate(const std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        void loadPriceHistory(const std::string& csvFile);
        void processInput(const std::string& inputFile);
};

#endif
