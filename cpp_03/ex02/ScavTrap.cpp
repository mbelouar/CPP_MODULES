#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor." << std::endl;
    name = "Unknown";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " parametric constructor." << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap " << src.getName() << " copy constructor." << std::endl;
}

ScavTrap	&ScavTrap::operator =(const ScavTrap &src)
{
	if (this != &src)
	{
		std::cout << "ScavTrap " << src.getName() << " copy assignement operator." << std::endl;
		this->name = src.getName();
		this->hitPoints = src.getHit_points();
		this->energyPoints = src.getEnergy_points();
		this->attackDamage = src.getAttack_points();
	}
	return *this;
}

void ScavTrap::guardGate() {
        std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
    }
}