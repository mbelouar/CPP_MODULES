#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor." << std::endl;
	this->name = "Unknown";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : 
    name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap parametric constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << src.getName() << " copy constructor." << std::endl;
	*this = src; // copy assignment operator called here
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &src)
{
	if (this != &src)
	{
		std::cout << "ClapTrap " << src.getName() << " copy assignement operator." << std::endl;
		this->name = src.getName();
		this->hitPoints = src.getHit_points();
		this->energyPoints = src.getEnergy_points();
		this->attackDamage = src.getAttack_points();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor." << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int	ClapTrap::getHit_points(void) const
{
	return this->hitPoints;
}

unsigned int	ClapTrap::getEnergy_points(void) const
{
	return this->energyPoints;
}

unsigned int	ClapTrap::getAttack_points(void) const
{
	return this->attackDamage;
}

void    ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints >= amount) {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't take any more damage. Hit points depleted." << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints >= 0 && energyPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points. Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't be repaired. Not enough hit points or energy points." << std::endl;
    }
}