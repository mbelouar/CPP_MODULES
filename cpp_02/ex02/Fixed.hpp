#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {
private:
	int					fixedPoint;
	static const int	fractBits = 8;
public:
	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator =(Fixed const &src);

	bool	operator >(Fixed const &rhs) const;
	bool	operator <(Fixed const &rhs) const;
	bool	operator >=(Fixed const &rhs) const;
	bool	operator <=(Fixed const &rhs) const;
	bool	operator ==(Fixed const &rhs) const;
	bool	operator !=(Fixed const &rhs) const;

	Fixed	operator +(Fixed const &rhs) const;
	Fixed	operator -(Fixed const &rhs) const;
	Fixed	operator *(Fixed const &rhs) const;
	Fixed	operator /(Fixed const &rhs) const;

	Fixed	&operator ++(); // prefix
	Fixed	operator ++(int); // postfix
	Fixed	&operator --();
	Fixed	operator --(int);
	
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &output, Fixed const &i);

#endif