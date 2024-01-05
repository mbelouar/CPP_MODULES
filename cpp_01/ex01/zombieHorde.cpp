#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    if (N <= 0) {
        std::cout << "Invalid input" << std::endl;
        return NULL; // Return NULL for invalid input
    }

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++){
        horde[i].setName(name);
    }
    return horde;
}