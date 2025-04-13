#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &diamondTrap);
		void whoAmI( void );
		using ScavTrap::attack;
	private:
		std::string name;
};
