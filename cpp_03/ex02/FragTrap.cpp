#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor." << std::endl;
}

void FragTrap::highFivesGuys() {
        std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
