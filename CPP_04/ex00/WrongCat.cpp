#include <iostream>
#include <string>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << " -> Default WrongCat constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout << " -> Parametric WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << " -> Copy WrongCat constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << " -> WrongCat destructor called." << std::endl;
}

WrongCat	&WrongCat::operator =(const WrongCat &src)
{
	if (this != &src)
	{
		std::cout << " -> Copy assignement WrongCat called." << std::endl;
		this->_type = src._type;
	}
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound, meow !" << std::endl;
}
