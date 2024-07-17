#include "Zombie.hpp"

Zombie::Zombie()
{ // default constructor
    std::cout << "Zombie Constructor." << std::endl;
}

Zombie::Zombie(std::string name)
{ // constructor that set the name passed in parameter to the variable object
    setName(name);
}

Zombie::~Zombie()
{
	std::cout << "\"" + getName() + "\"" << " is destroyed." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

std::string Zombie::getName(){
    return this->_name;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}