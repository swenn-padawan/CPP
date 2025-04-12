#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &scavtrap);
		~ScavTrap();

		void	guardGate( void );
		void	attack( const std::string &target );
};
