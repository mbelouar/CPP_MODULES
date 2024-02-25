#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor." << std::endl;
    name = "Unknown";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " parametric constructor." << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap " << src.getName() << " copy constructor." << std::endl;
}

FragTrap	&FragTrap::operator =(const FragTrap &src)
{
	if (this != &src)
	{
		std::cout << "FragTrap " << src.getName() << " copy assignement operator." << std::endl;
		this->name = src.getName();
		this->hitPoints = src.getHit_points();
		this->energyPoints = src.getEnergy_points();
		this->attackDamage = src.getAttack_points();
	}
	return *this;
}

void FragTrap::highFivesGuys() {
        std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
