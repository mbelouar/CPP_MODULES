#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed {
private:
	int					_fp;
	static const int	_frac = 8;
public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif