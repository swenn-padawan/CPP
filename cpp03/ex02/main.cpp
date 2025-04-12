#include "FragTrap.hpp"

int main()
{
	FragTrap frag("fraggy");	
	FragTrap fragNoName;	

	frag.attack("bertrand le chasseur");
	frag.takeDamage(20);
	frag.beRepaired(20);
	frag.attack("bertrand le chasseur");
	frag.takeDamage(100);
	frag.beRepaired(20);
	frag.highFivesGuys();	
	fragNoName.attack("bertrand le chasseur");
	fragNoName.takeDamage(20);
	fragNoName.beRepaired(20);
	fragNoName.attack("bertrand le chasseur");
	fragNoName.takeDamage(100);
	fragNoName.beRepaired(20);
}
