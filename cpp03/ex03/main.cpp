#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	diamant("Diamond");
	DiamondTrap	undefined;
		
	diamant.whoAmI();
	undefined.whoAmI();
	diamant.attack("cible");
	diamant.beRepaired(80);
	diamant.guardGate();
	diamant.highFivesGuys();
	diamant.takeDamage(90);

	std::cout << "And Now With The Default Constructor !!!" << std::endl;

	undefined.attack("cible");
	undefined.whoAmI();
	undefined.beRepaired(80);
	undefined.guardGate();
	undefined.highFivesGuys();
	undefined.takeDamage(90);
}
