#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
    : _name(name)
{
    std::cout << "HumanB named " << name << " created." << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB named " << _name << " destroyed." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return;
}

void HumanB::attack() {
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}