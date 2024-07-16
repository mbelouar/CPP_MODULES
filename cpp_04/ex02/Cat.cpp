#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor." << std::endl;
    type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
    std::cout << "Cat copy contructor." << std::endl;
    this->_brain = new Brain();
    *this = src;
}

Cat &Cat::operator= (const Cat &src) {
    if (this != &src)
    {
        std::cout << "Cat copy assignment operator." << std::endl;
        this->type = src.getType();
        this->_brain->setIdeas(src._brain->getIdeas()); // deep copy
		//this->_brain = src._brain; // shallow copy
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor." << std::endl;
    delete this->_brain;
}

void    Cat::makeSound() const {
    std::cout << "Cat sound - meaw meaw" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return this->_brain;
}