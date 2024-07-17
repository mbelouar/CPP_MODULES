#include "Zombie.hpp"

Zombie::Zombie()
{
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