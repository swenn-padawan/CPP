#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap Default Constructor has been called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	this->name = "undefined";
};

FragTrap::FragTrap(std::string name){
	std::cout << "FragTrap Constructor has been called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &copy){
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &fragtrap){
	if (&fragtrap == this)
		return (*this);
	this->hitPoints = fragtrap.hitPoints;
	this->energyPoints = fragtrap.energyPoints;
	this->attackDamage = fragtrap.attackDamage;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys( void ){
	std::cout << MAGENTA << "FragTrap " << this->name << " want to make a high Fives !" << RESET << std::endl;
}
