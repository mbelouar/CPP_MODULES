#include "ClapTrap.hpp"

// int main() {
//     ClapTrap claptrap("CLAP-001");

//     claptrap.attack("Enemy1");
//     claptrap.takeDamage(5);
//     claptrap.beRepaired(3);
//     claptrap.attack("Enemy2");

//     return 0;
// }

int	main(void)
{
	ClapTrap	bob = ClapTrap("Bob");

	ClapTrap	bib = bob;
	ClapTrap	bubs[3];

	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");

	bob.takeDamage(9);
	bob.attack("a worm");
	bob.takeDamage(1);
    std::cout << "\n";
	bob.attack("a worm"); // No more life
	bob.attack("a worm"); // If have one more life, will not have enought energy
}