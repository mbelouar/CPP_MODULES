#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor." << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &src) {
    std::cout << "Dog copy contructor." << std::endl;
    *this = src;
}

Dog &Dog::operator= (const Dog &src) {
    if (this != &src)
    {
        std::cout << "Dog copy assignment operator." << std::endl;
        this->type = src.getType();
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor." << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "Dog sound - haw haw" << std::endl;
}