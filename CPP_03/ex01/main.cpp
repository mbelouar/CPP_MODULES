#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scavtrap = ScavTrap("\"SCAV-001\"");

    scavtrap.guardGate();
    scavtrap.attack("Enemy1");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(15);
    scavtrap.guardGate();

    // ScavTrap simo = ScavTrap("simo");

    // ScavTrap bickle;
    // bickle = simo;
    return 0;
}


// int	main(void)
// {
// 	ClapTrap	bob = ClapTrap("Bob");

// 	bob.attack("a worm");
// 	bob.takeDamage(9);

// 	ScavTrap	bib = ScavTrap("Bib");
// 	ScavTrap	bubs[2];

// 	bib.attack("a human");
// 	bib.guardGate();
// 	bib.guardGate();
// 	bib.beRepaired(5);
// }