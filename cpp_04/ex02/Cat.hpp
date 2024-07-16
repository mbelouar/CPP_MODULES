#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {
    private:
	    Brain	*_brain;
    public :
        Cat();
        Cat(const Cat &src);
        virtual ~Cat();

        Cat &operator =(const Cat &src);

        void    makeSound() const;
        Brain	*getBrain(void) const;
};

#endif