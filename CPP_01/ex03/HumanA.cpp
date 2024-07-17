#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _weapon(weapon), _name(name) {
    std::cout << "HumanA named " << name << " created." << std::endl;
}

HumanA::~HumanA() {
    std::cout << "HumanA named " << _name << " destroyed." << std::endl;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}