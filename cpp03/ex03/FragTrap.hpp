#include "ScavTrap.hpp"

class FragTrap: virtual public ClapTrap{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const std::string _name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &fragtrap);
		void	highFivesGuys(void);
};
