#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &scavtrap);
		~ScavTrap();
		void	attack(const std::string& target);

		void	guardGate( void );
};
