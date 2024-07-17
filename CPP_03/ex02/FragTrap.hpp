#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
        
    public :
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &src);
        ~FragTrap();

        FragTrap    &operator =(const FragTrap &src);

        void highFivesGuys();
};

#endif