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

	Fixed	&operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif