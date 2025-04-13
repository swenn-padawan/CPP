#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "Constructor has been called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(): name("undefinded"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap){
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	this->name = claptrap.name;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->hitPoints <= 0){
		std::cout << GRAY << "ClapTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	if (this->energyPoints < 1){
		std::cout << GRAY << "ClapTrap " << this->name << " has no energy"<< RESET << std::endl;
		return ;
	}
	std::cout<< BLUE << "Claptrap " << this->name << " attack " << target << " causing " << this->attackDamage << " points of damage!"<< RESET << std::endl;
	this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints <= 0){
		std::cout << GRAY << "ClapTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	std::cout << RED << "Claptrap " << this->name << " has taken " << amount << " of damage" << RESET << std::endl;
	this->hitPoints -= amount;
	std::cout << this->name << " have now " << this->hitPoints <<" Hit Points" << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " Dies !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hitPoints <= 0){
		std::cout << GRAY << "ClapTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	if (this->energyPoints < 1){
		std::cout << GRAY <<"ClapTrap " << this->name << " has no energy"<< RESET <<std::endl;
		return ;
	}
	std::cout << GREEN << "Claptrap " << this->name << " has repaired itself for " << amount << " points"<< std::endl;
	this->hitPoints += amount;
	if (this->hitPoints > 10)
		this->hitPoints -= this->hitPoints - 10;
	std::cout << this->name << " have now " << this->hitPoints <<" Hit Points"<< RESET << std::endl;
	this->energyPoints -= 1;
}
