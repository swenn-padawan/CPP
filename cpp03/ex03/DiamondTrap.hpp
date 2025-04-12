#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &diamondTrap);
		void whoAmI( void );
		using ScavTrap::attack;
	private:
		std::string name;
};
