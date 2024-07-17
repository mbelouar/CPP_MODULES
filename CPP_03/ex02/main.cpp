#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap fragtrap = FragTrap("\"FRAG-001\"");

    FragTrap gg = fragtrap;

    fragtrap.highFivesGuys();
    fragtrap.attack("Enemy1");
    fragtrap.takeDamage(40);
    fragtrap.beRepaired(20);

    return 0;
}

// int	main(void)
// {
// 	ClapTrap	bob = ClapTrap("Bob");

// 	bob.attack("a worm");
// 	bob.takeDamage(9);

// 	FragTrap	bib = FragTrap("Bib");
// 	//FragTrap	bubs[2];
// 	//FragTrap	bab = bib;

// 	bib.attack("a human");
// 	bib.highFivesGuys();
// 	bib.beRepaired(5);
// }
