#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        this->priceHistory = src.priceHistory;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadPriceHistory(const std::string& csvFile) {
    std::ifstream file(csvFile);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open csv file " << csvFile << std::endl;
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

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    try {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0 || year > 9999)
            return false;
    } catch (const std::exception &e) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {
    try {
        double value = std::stod(valueStr);
        if (value < 0 || value > 1000)
            return false;
    } catch (const std::exception &e) {
        return false;
    }
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, double>::iterator it = priceHistory.lower_bound(date);
    if (it != priceHistory.end() && it->first == date) {
        // If the exact date is found, return it directly.
        return it->first;
    }

    // lower_bound will point to the next heighest key => ( next = it )
    std::map<std::string, double>::iterator next = it;
    std::map<std::string, double>::iterator prev = (it == priceHistory.begin()) ? priceHistory.end() : std::prev(it);

    // Calculate the difference as the number of days between the input date and prev/next dates
    int prevDiff = std::abs(std::stoi(prev->first.substr(0, 4) + prev->first.substr(5, 2) + prev->first.substr(8, 2)) -
                            std::stoi(date.substr(0, 4) + date.substr(5, 2) + date. substr(8, 2)));
    int nextDiff = std::abs(std::stoi(next->first.substr(0, 4) + next->first.substr(5, 2) + next->first.substr(8, 2)) -
                            std::stoi(date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2)));

    return (nextDiff < prevDiff) ? next->first : prev->first;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
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