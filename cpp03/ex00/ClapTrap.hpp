#include <iostream>
#include "colors.hpp"

class ClapTrap{

	public:
		ClapTrap(std::string name);
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &claptrap);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
};
