#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Constructor

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called." << std::endl;
	this->_fp = 0;
	return;
}

Fixed::Fixed(const int x)
{
	//std::cout << "Int constructor called." << std::endl;
	this->_fp = x << this->_frac;
	return;
}

Fixed::Fixed(const float x)
{
	//std::cout << "Float constructor called." << std::endl;
	this->_fp = roundf(x * (1 << this->_frac));
	return;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return;
}

// Destructor

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called." << std::endl;
	return;
}

// Assignement
Fixed	&Fixed::operator =(Fixed const &src)
{
	//std::cout << "Copy assignement operator called." << std::endl;
	if (this != &src)
		this->_fp = src.getRawBits();
	return *this;
}

// Comparison

bool	Fixed::operator >(Fixed const &src) const
{
	return this->_fp > src._fp;
}

bool	Fixed::operator <(Fixed const &src) const
{
	return this->_fp < src._fp;
}

bool	Fixed::operator >=(Fixed const &src) const
{
	return this->_fp >= src._fp;
}

bool	Fixed::operator <=(Fixed const &src) const
{
	return this->_fp <= src._fp;
}

bool	Fixed::operator ==(Fixed const &src) const
{
	return this->_fp == src._fp;
}

bool	Fixed::operator !=(Fixed const &src) const
{
	return this->_fp != src._fp;
}

// Arithmetic

Fixed	Fixed::operator+(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits(this->_fp + src._fp);
	return result;
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits(this->_fp - src._fp);
	return result;
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits((this->_fp * src._fp) >> this->_frac);
	return result;
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	Fixed	result;

	result.setRawBits((this->_fp << this->_frac) / src._fp);
	return result;
}

// Increment / decrement
Fixed&	Fixed::operator ++()
{
	this->_fp++;
	return *this;
}

Fixed	Fixed::operator ++(int)
{
	Fixed	temp(*this);

	this->_fp++;
	return temp;
}

Fixed&	Fixed::operator --()
{
	this->_fp--;
	return *this;
}

Fixed	Fixed::operator --(int)
{
	Fixed	temp(*this);

	this->_fp--;
	return temp;
}

// Member functions

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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

// ostream overloading

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}
