#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor." << std::endl;
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