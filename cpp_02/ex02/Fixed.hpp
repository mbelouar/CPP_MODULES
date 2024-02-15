#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {
private:
	int					_fp;
	static const int	_frac = 8;
public:
	Fixed(void);
	Fixed(const int x);
	Fixed(const float x);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator =(Fixed const &src);

	// comparison
	bool	operator >(Fixed const &src) const;
	bool	operator <(Fixed const &src) const;
	bool	operator >=(Fixed const &src) const;
	bool	operator <=(Fixed const &src) const;
	bool	operator ==(Fixed const &src) const;
	bool	operator !=(Fixed const &src) const;

	// arithmetic
	Fixed	operator +(Fixed const &src) const;
	Fixed	operator -(Fixed const &src) const;
	Fixed	operator *(Fixed const &src) const;
	Fixed	operator /(Fixed const &src) const;

	// increment / decrement
	Fixed	&operator ++(); // prefix
	Fixed	operator ++(int); // postfix
	Fixed	&operator --(); // prefix
	Fixed	operator --(int); // postfix
	
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif