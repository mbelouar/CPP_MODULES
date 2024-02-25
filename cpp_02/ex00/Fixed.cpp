#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;   // calling the copy assignment operator within the copy constructor
	// this->fixedPoint = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignement operator called." << std::endl;
	if (this != &src)
		this->fixedPoint = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return this->fixedPoint;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->fixedPoint = raw;
}