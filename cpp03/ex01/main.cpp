#include "ScavTrap.hpp"

int main()
{
	ScavTrap	scav("le scav");
	ScavTrap	clap;

	scav.guardGate();
	scav.attack("bertrand le chasseur");
	scav.takeDamage(20);
	scav.beRepaired(20);
	scav.attack("bertrand le chasseur");
	scav.takeDamage(100);
	scav.beRepaired(20);

	clap.attack("bertrand le chasseur");
	clap.takeDamage(20);
	clap.beRepaired(20);
	clap.attack("bertrand le chasseur");
	clap.takeDamage(100);
	clap.beRepaired(20);
}
