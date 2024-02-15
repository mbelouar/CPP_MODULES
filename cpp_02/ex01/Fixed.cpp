#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->_fp = 0;
	return;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called." << std::endl;
	this->_fp = x << this->_frac;
	return;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called." << std::endl;
	this->_fp = roundf(x * (1 << this->_frac));
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
	return this->_fp;
}

void	Fixed::setRawBits(const int raw)
{
	this->_fp = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_fp / (float)(1 << this->_frac);
}

int	Fixed::toInt(void) const
{
	return roundf(this->_fp / (1 << this->_frac));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}