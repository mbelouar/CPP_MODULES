#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main()
{
	std::cout << " -> Create the Zombie Simo." << std::endl;
	Zombie simo = Zombie("Simo");
	simo.announce();

	std::cout << " -> Create the Zombie Bickle with newZombie()." << std::endl;
	Zombie*	Bickle = newZombie("Bickle");
	Bickle->announce();
	delete Bickle;

	std::cout << " -> Create the Zombie bello with randomChump()." << std::endl;
	randomChump("bello");

	return 0;
}