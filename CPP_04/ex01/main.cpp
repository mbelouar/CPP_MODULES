#include <iostream>
#include <string>
#include <string.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {

    const int animalCount = 6;
    Animal* animals[animalCount];
    std::cout << "============== DOGS ===============" << std::endl;
    for (int i = 0; i < animalCount / 2; ++i) {
        animals[i] = new Dog();
    }

    std::cout << "=============== CATS ==============" << std::endl;
    for (int i = animalCount / 2; i < animalCount; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "============== DESTRUCTION ===============" << std::endl;
    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
        std::cout << "------------" << std::endl;
    }
    std::cout << "============== END ===============" << std::endl;

    return 0;
}