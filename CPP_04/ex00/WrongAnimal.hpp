#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <string>

class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &src);
	virtual		~WrongAnimal();
	WrongAnimal &operator	=(const WrongAnimal &src);

	std::string				getType(void) const;
	void					makeSound(void) const;
};

#endif