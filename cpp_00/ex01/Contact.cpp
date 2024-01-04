#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName()
{
    return this->_firstName;
}
std::string Contact::getLastName()
{
    return this->_lastName;
}
std::string Contact::getNickName()
{
    return this->_nickName;
}
std::string Contact::getPhoneNumber()
{
    return this->_phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return this->_darkestSecret;
}

void	Contact::setFirstName(std::string firstname)
{
	this->_firstName = firstname;
}

void Contact::setLastName(std::string lastname)
{
	this->_lastName = lastname;
}

void Contact::setNickName(std::string nickename)
{
	this->_nickName = nickename;
}

void Contact::setPhoneNumber(std::string phonenumber)
{
	this->_phoneNumber = phonenumber;
}

void Contact::setDarkestSecret(std::string darkestsecret)
{
	this->_darkestSecret = darkestsecret;
}
