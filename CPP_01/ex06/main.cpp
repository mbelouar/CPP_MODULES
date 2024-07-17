#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl = Harl();

	if (ac == 2)
		harl.complain(av[1]);
	else
		harl.complain("");
	return 0;
}
