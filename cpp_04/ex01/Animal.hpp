#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &src);
        virtual ~Animal();

        Animal  &operator =(const Animal &src);

        std::string getType() const;
        virtual void    makeSound() const;
        virtual Brain	*getBrain(void) const = 0;
};

#endif