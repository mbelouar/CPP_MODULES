#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include  <climits>
# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        unsigned int     _current;
        unsigned int     _index;

    public:
        PhoneBook();
        ~PhoneBook();
        void	addContact();
        void	searchContact();
        void    listContacts();
        std::string truncateString(const std::string& str, int maxWidth);

};

#endif // PHONEBOOK_HPP
