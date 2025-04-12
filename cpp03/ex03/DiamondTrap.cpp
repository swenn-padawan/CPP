#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap(), FragTrap(), ScavTrap(), name("undefined"){
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap( const std::string _name )
	: ClapTrap(_name + "_clap_name"),
	FragTrap(),
	ScavTrap(),
	name(_name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy){
	*this = copy;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap){
	if (&diamondTrap == this)
		return (*this);
	this->name = diamondTrap.name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI( void ){
	std::cout << CYAN << "My name is " << name << " and " << ClapTrap::name << RESET << std::endl;
}
