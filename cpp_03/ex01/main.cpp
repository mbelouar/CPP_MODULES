#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CLAP-001");

    claptrap.attack("Enemy1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("Enemy2");

    return 0;
}