#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called." << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int x)
{
	// std::cout << "Int constructor called." << std::endl;
	this->fixedPoint = x << this->fractBits;
}

Fixed::Fixed(const float x)
{
	// std::cout << "Float constructor called." << std::endl;
	this->fixedPoint = roundf(x * (1 << this->fractBits));
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called." << std::endl;
}

// Assignement
Fixed	&Fixed::operator =(Fixed const &src)
{
	// std::cout << "Copy assignement operator called." << std::endl;
	if (this != &src)
		this->fixedPoint = src.getRawBits();
	return *this;
}

// Comparison
bool	Fixed::operator >(Fixed const &rhs) const
{
	return this->fixedPoint > rhs.fixedPoint;
}

bool	Fixed::operator <(Fixed const &rhs) const
{
	return this->fixedPoint < rhs.fixedPoint;
}

bool	Fixed::operator >=(Fixed const &rhs) const
{
	return this->fixedPoint >= rhs.fixedPoint;
}

bool	Fixed::operator <=(Fixed const &rhs) const
{
	return this->fixedPoint <= rhs.fixedPoint;
}

bool	Fixed::operator ==(Fixed const &rhs) const
{
	return this->fixedPoint == rhs.fixedPoint;
}

bool	Fixed::operator !=(Fixed const &rhs) const
{
	return this->fixedPoint != rhs.fixedPoint;
}

// Arithmetic
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(this->fixedPoint + rhs.fixedPoint);
	return result;
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(this->fixedPoint - rhs.fixedPoint);
	return result;
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits((this->fixedPoint * rhs.fixedPoint) >> this->fractBits);
	return result;
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits((this->fixedPoint << this->fractBits) / rhs.fixedPoint);
	return result;
}

// Increment / decrement
Fixed&	Fixed::operator ++()
{
	this->fixedPoint++;
	return *this;
}

Fixed	Fixed::operator ++(int)
{
	Fixed	tmp(*this);

	this->fixedPoint++;
	return tmp;
}

Fixed&	Fixed::operator --()
{
	this->fixedPoint--;
	return *this;
}

Fixed	Fixed::operator --(int)
{
	Fixed	tmp(*this);

	this->fixedPoint--;
	return tmp;
}

// Member functions
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
}

int	Fixed::toInt(void) const
{
	return roundf(this->fixedPoint / (1 << this->fractBits));
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
std::ostream	&operator<<(std::ostream &output, Fixed const &f)
{
	output << f.toFloat();
	return output;
}
