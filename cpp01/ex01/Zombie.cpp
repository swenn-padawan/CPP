/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:23:31 by stetrel           #+#    #+#             */
/*   Updated: 2025/03/06 16:20:28 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
	std::cout << "A Zombie" << " has been created !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << getName() << " has been destructed !" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName( void )
{
	return (this->name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
