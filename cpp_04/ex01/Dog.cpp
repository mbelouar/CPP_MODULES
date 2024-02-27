#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor." << std::endl;
    type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog copy contructor." << std::endl;
    this->_brain = new Brain();
    *this = src;
}

Dog &Dog::operator= (const Dog &src) {
    if (this != &src)
    {
        std::cout << "Dog copy assignment operator." << std::endl;
        this->type = src.getType();
        this->_brain->setIdeas(src._brain->getIdeas()); // deep copy
		//this->_brain = src._brain; // shallow copy
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor." << std::endl;
    delete this->_brain;
}

void    Dog::makeSound() const {
    std::cout << "Dog sound - haw haw" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return this->_brain;
}