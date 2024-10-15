#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange::BitcoinExchange &operator=(const BitcoinExchange &src) {
    if (this != &src) {
        this->priceHistory = src.priceHistory;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadPriceHistory(const std::string& csvFile) {
    std::ifstream file(csvFile);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << csvFile << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        if (isValidDate(date) && isValidValue(value)) {
            priceHistory[date] = std::stod(value);
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& valueStr) {
    try {
        double value = std::stod(valueStr);
        if (value < 0 || value > 1000) return false;
    } catch (const std::exception &e) {
        return false;
    }
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    auto it = priceHistory.lower_bound(date);
    if (it != priceHistory.begin() && (it == priceHistory.end() || it->first != date)) {
        --it; // Move to the previous date
    }
    return it->first;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date = date.substr(0, date.find_last_not_of(" \t") + 1); // Trim spaces
            valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            if (!isValidValue(valueStr)) {
                double value = std::stod(valueStr);
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                } else {
                    std::cerr << "Error: too large a number." << std::endl;
                }
                continue;
            }

            double value = std::stod(valueStr);
            std::string closestDate = findClosestDate(date);
            double exchangeRate = priceHistory[closestDate];
            double result = value * exchangeRate;

            std::cout << date << " => " << value << " = " << result << std::endl;
        } else {
            std::cerr << "Error: bad input." << std::endl;
        }
    }

    file.close();
}