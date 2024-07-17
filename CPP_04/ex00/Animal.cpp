#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor." << std::endl;
    this->type = "None";
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal copy constructor." << std::endl;
    *this = src; // copy assignment operator called
}

Animal	&Animal::operator =(const Animal &src) {
    if (this != &src)
    {
        std::cout << "Animal copy assignment operator." << std::endl;
        this->type = src.getType();
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor." << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void    Animal::makeSound() const {
    std::cout << "Animal sound." << std::endl; 
}
