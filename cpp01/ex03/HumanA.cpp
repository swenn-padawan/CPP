#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(&weapon), _name(name){};

HumanA::~HumanA( void ){}

void	HumanA::attack( void )
{
	std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
}


