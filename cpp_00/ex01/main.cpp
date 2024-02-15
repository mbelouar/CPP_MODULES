#include "PhoneBook.hpp"

int main() {
    PhoneBook myPhoneBook;
    std::string command;

    while (std::cin) {
        std::cout << std::endl << "================= PHONEBOOK MENU ====================" << std::endl;
        std::cout << "|  ADD    : to add a new contact to your phonebook. |" << std::endl;
        std::cout << "|  SEARCH : to search for contacts.                 |" << std::endl;
        std::cout << "|  EXIT   : to exit the program.                    |" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << std::endl << "Enter command\t: ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            myPhoneBook.addContact();
        } else if (command == "SEARCH") {
            myPhoneBook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Exiting program. Contacts will be lost forever!" << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <string>
// #include <cstdlib>

// void getInput(std::string& str, const std::string& prompt) {
//     do {
//         std::cout << prompt;
//         std::getline(std::cin, str);

//         if (std::cin.eof()) {
//             std::cout << std::endl;
//             exit(EXIT_SUCCESS);
//         }
//     } while (str.empty());
// }

// int main() {
//     std::string userInput;
//     getInput(userInput, "Enter something: ");
//     std::cout << "You entered: " << userInput << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int value;

//     std::cout << "Enter an integer: ";
//     std::cin >> value;

//     if (std::cin.fail()) {
//         std::cout << "Invalid input! Please enter an integer." << std::endl;
//     } else {
//         std::cout << "You entered: " << value << std::endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <iomanip>

// int main() {
//     std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::setw(10) << "City" << std::endl;
//     std::cout << std::setw(10) << "John" << std::setw(10) << 25 << std::setw(10) << "New York" << std::endl;
//     std::cout << std::setw(10) << "Alice" << std::setw(10) << 30 << std::setw(10) << "London" << std::endl;

//     return 0;
// }
