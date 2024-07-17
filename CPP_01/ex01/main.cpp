#include "Zombie.hpp"

Zombie*     zombieHorde(int N, std::string name);

int main()
{
    Zombie* horde = zombieHorde(3, "smimo");
    for (int i = 0; i < 3; i++){
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}