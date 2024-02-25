#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed {
private:
	int					fixedPoint;
	static const int	fractBits = 8;
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif