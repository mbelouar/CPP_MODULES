#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Default AAnimal constructor called." << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Parametric AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Copy AAnimal constructor calld." << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal	&AAnimal::operator =(const AAnimal &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignement AAnimal called." << std::endl;
		this->type = src.type;
	}
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return this->type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "I don't have a sound : am an animal." << std::endl;
}