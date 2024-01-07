#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name) : 
    name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructor." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor." << std::endl;
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
    if (hitPoints > amount) {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't take any more damage. Hit points depleted." << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points. Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't be repaired. Not enough hit points or energy points." << std::endl;
    }
}