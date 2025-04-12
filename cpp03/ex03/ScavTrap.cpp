/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:52:47 by stetrel           #+#    #+#             */
/*   Updated: 2025/04/12 16:17:39 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap Destructor has been called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	this->name = "undefined";
}

ScavTrap::ScavTrap(std::string name){
	std::cout << "ScavTrap Constructor has been called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &copy){
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap){
	if (&scavtrap == this)
		return (*this);
	this->hitPoints = scavtrap.hitPoints;
	this->energyPoints = scavtrap.energyPoints;
	this->attackDamage = scavtrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (this->hitPoints <= 0){
		std::cout << GRAY << "ScavTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	if (this->energyPoints < 1){
		std::cout << GRAY << this->name << " has no energy"<< RESET << std::endl;
		return ;
	}
	std::cout<< BLUE << this->name << " attack " << target << " causing " << this->attackDamage << " points of damage!"<< RESET << std::endl;
	this->energyPoints -= 1;
}

void ScavTrap::guardGate(){
	std::cout << YELLOW << this->name << " is now in gate keeper mode" << RESET << std::endl;
}
