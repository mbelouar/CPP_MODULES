#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->_fp = 0;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignement operator called." << std::endl;
	if (this != &src)
		this->_fp = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return this->_fp;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_fp = raw;
	return;
}