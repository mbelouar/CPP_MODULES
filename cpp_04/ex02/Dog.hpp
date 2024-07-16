#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal {
    private:
	    Brain	*_brain;   
    public :
        Dog();
        Dog(const Dog &src);
        virtual ~Dog();

        Dog &operator =(const Dog &src);

        void    makeSound() const;
        Brain	*getBrain(void) const;
};

#endif