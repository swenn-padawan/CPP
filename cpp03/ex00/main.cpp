#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap("Trappy");
	ClapTrap trappy;

	trap.attack("ennemy");
	trap.beRepaired(12);
	trap.takeDamage(8);
	trap.takeDamage(8);
	trap.attack("ennemy");

	std::cout << YELLOW << "And now with the default constructor !!!" << std::endl;

	trappy.beRepaired(12);
	trappy.takeDamage(8);
	trappy.takeDamage(8);
	trappy.attack("ennemy");
}
