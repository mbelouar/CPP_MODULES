#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
    private :
        std::string  name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
	    ~ClapTrap();
	    ClapTrap	&operator =(const ClapTrap &src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // Getters
        std::string		getName(void) const;
	    unsigned int	getHit_points(void) const;
	    unsigned int	getEnergy_points(void) const;
	    unsigned int	getAttack_points(void) const;
};

#endif