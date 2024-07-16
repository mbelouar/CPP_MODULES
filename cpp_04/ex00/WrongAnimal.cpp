#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << " -> Default WrongAnimal constructor called." << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << " -> Parametric WrongAnimal constructor called." << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << " -> Copy WrongAnimal constructor calld." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << " -> WrongAnimal destructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator =(const WrongAnimal &src)
{
	if (this != &src)
	{
		std::cout << " -> Copy assignement WrongAnimal called." << std::endl;
		this->_type = src._type;
	}
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal, I don't have any sound..." << std::endl;
}
