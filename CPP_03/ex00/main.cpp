#include "ClapTrap.hpp"

// int main() {
//     ClapTrap	bob = ClapTrap("Bob");

// 	ClapTrap	bib = bob; // copy constructor

// 	bob.attack("a worm"); // -1 energyPoint
// 	bob.attack("a worm"); // -1 energyPoint
// 	bob.attack("a worm"); // -1 energyPoint
// 	bob.attack("a worm"); // -1 energyPoint
// 	bob.attack("a worm"); // -1 energyPoint
// 	bob.attack("a worm"); // -1 energyPoint

// 	// -6 energyPoints ==> 4 energyPoints remain 

// 	std::cout << "\nBefore TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;
// 	bob.takeDamage(9);
// 	std::cout << "After TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;
// 	// still 4 energyPoints cuz takeDamage dont spend any amount of energyPoints

// 	std::cout << "\nBefore ATTACKING : energyPoints = " << bob.getEnergy_points() << std::endl;
// 	bob.attack("a worm");
// 	std::cout << "After ATTACKING : energyPoints = " << bob.getEnergy_points() << std::endl;
// 	// after attacking we lose 1 energyPoint 
// 	// 3 energyPoints still
// 	std::cout << "Hit Points = " << bob.getHit_points() << std::endl;
	
// 	std::cout << "\nBefore TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;
// 	bob.takeDamage(1);
// 	std::cout << "Hit Points = " << bob.getHit_points() << std::endl;
// 	std::cout << "After TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;
	
// 	// at this part there's no more hit points all is depleted
// 	std::cout << "\n";
// 	bob.beRepaired(1);
// 	std::cout << "Hit Points after repairing = " << bob.getHit_points() << std::endl;
// 	bob.attack("SMAYKA"); // No more life
// 	bob.attack("SMAYKA"); // If have one more life, will not have enought energy




// 	std::cout << "Before ATTACKING : energyPoints = " << bob.getEnergy_points() << std::endl;
//     bob.attack("Enemy1");
// 	std::cout << "After ATTACKING : energyPoints = " << bob.getEnergy_points() << std::endl;

// 	std::cout << "\nBefore TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;
//     bob.takeDamage(5);
// 	std::cout << "After TAKE DAMAGE : energyPoints = " << bob.getEnergy_points() << std::endl;

// 	std::cout << "\nBefore REPAIRING : energyPoints = " << bob.getEnergy_points() << std::endl;
//     bob.beRepaired(3);
// 	std::cout <<  "After REPAIRING : energyPoints = " << bob.getEnergy_points() << std::endl<<std::endl;

//     bob.attack("Enemy2");

//     return 0;
// }

int	main(void)
{
	ClapTrap	bob = ClapTrap("\"Bob\"");

	ClapTrap	bib = bob; // copy constructor
	ClapTrap	bubs[3];

	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	// -8 energyPoints
	bob.takeDamage(9);  // 1 hitPoint remain
	bob.attack("a worm"); // -9 energyPoints
	bob.takeDamage(1); // 0 hitPoint remain


    std::cout << "\n";
	bob.attack("a worm"); // No more life
	bob.attack("a worm"); // If have one more life, will not have enought energy
}