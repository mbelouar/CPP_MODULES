#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor." << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &src) {
    std::cout << "Cat copy contructor." << std::endl;
    *this = src;
}

Cat &Cat::operator= (const Cat &src) {
    if (this != &src)
    {
        std::cout << "Cat copy assignment operator." << std::endl;
        this->type = src.getType();
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor." << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "Cat sound - meww meww" << std::endl;
}