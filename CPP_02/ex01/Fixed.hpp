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

	Fixed	&operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output, Fixed const &i);

#endif