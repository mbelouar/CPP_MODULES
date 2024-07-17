#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _current = 0;
    _index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string  _firstname;
    std::string  _lastname;
    std::string  _nickname;
    std::string	_phonenumber;
    std::string	_darkestsecret;

    std::cout << std::endl;
    std::cout << "\tFirst Name\t[]: ";
    getline(std::cin, _firstname);
    newContact.setFirstName(_firstname);

    std::cout << "\tLast Name\t[]: ";
    getline(std::cin, _lastname);
    newContact.setLastName(_lastname);

    std::cout << "\tNickname\t[]: ";
    getline(std::cin, _nickname);
    newContact.setNickName(_nickname);

    std::cout << "\tPhone Number\t[]: ";
    getline(std::cin, _phonenumber);
    newContact.setPhoneNumber(_phonenumber);

    std::cout << "\tDarkest Secret\t[]: ";
    getline(std::cin, _darkestsecret);
    newContact.setDarkestSecret(_darkestsecret);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    if (_current < 8) {
        // If there's space in the array, add the contact to the next available slot
        _contacts[_current] = newContact;
        _current++;
        _index = _current;
    } else {
        // If the array is full, replace the (current % 8)-th oldest contact
        int replaceIndex = _current % 8;  // Calculate the replace index
        _contacts[replaceIndex] = newContact;
        _current++;
        _index = 8;  // Update _index to indicate that all slots are filled
    }

    std::cout << std::endl << "\"" << _firstname+" "+_lastname << "\"" << " ADDED SUCCESSFULLY" << std::endl;
}

std::string PhoneBook::truncateString(const std::string& str, int maxWidth)
{
    if ((int)str.length() <= maxWidth)
    {
        return str;
    }
    else
    {
        // Truncate and replace the last displayable character with a dot
        return str.substr(0, maxWidth - 1) + ".";
    }
}

void PhoneBook::listContacts()
{
    const int columnWidth = 10;

    std::cout << std::endl << "\t|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    std::cout << "\t---------------------------------------------" << std::endl;
    for (int i = 0; i < (int)this->_index; i++)
    {
        std::cout << "\t|" << std::setw(columnWidth) << i;
        std::cout << "|" << std::setw(columnWidth) << truncateString(this->_contacts[i].getFirstName(), columnWidth);
        std::cout << "|" << std::setw(columnWidth) << truncateString(this->_contacts[i].getLastName(), columnWidth);
        std::cout << "|" << std::setw(columnWidth) << truncateString(this->_contacts[i].getNickName(), columnWidth);
        std::cout << "|" << std::endl;
    }
    
    std::cout << "\t---------------------------------------------" << std::endl;
}

void PhoneBook::searchContact() {
    unsigned int index;
    
    listContacts();
    std::cout << "Enter the index\t: ";
    std::cin >> index;

    if (std::cin.fail()) {
        std::cout << "Invalid index!" << std::endl;
    }
    else {
        if (index < this->_index) {
            std::cout << "The information od the contact that you are looking for : " << std::endl;
            std::cout << "\tFirst Name        : " << this->_contacts[index].getFirstName() << std::endl;
            std::cout << "\tLast Name         : " << this->_contacts[index].getLastName() << std::endl;
            std::cout << "\tNickname          : " << this->_contacts[index].getNickName() << std::endl;
            std::cout << "\tPhone Number      : " << this->_contacts[index].getPhoneNumber() << std::endl;
            std::cout << "\tDarkest Secret    : " << this->_contacts[index].getDarkestSecret() << std::endl;
        }
        else {
            std::cout << "ATTENTION!: Index not in the range " << std::endl;
        }
    }
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');  // Clear the input buffer
}
