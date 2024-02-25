#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called." << std::endl;
	this->fixedPoint = x << this->fractBits;
	// this->fixedPoint = x * (1 << this->fractBits);
	// this->fixedPoint = x * pow(2, this->fractBits);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called." << std::endl;
	this->fixedPoint = roundf(x * (1 << this->fractBits));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
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
	return this->fixedPoint;
}

void	Fixed::setRawBits(const int raw)
{
	this->fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->fixedPoint / (float)(1 << this->fractBits);
	// return (float)this->fixedPoint / (float)(pow(2, this->fractBits));
}

int	Fixed::toInt(void) const
{
	return roundf(this->fixedPoint / (1 << this->fractBits));
	// return roundf(this->fixedPoint / pow(2, this->fractBits));
}

/*
	Inserts a floating-point representation
	of the fixed-point number into the output
	stream object passed as parameter.
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &f)
{
	output << f.toFloat();
	return output;
}