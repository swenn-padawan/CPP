/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:20:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/03/05 19:55:18 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		Zombie(void);
		~Zombie(void);
		void announce( void );
		
		std::string getName( void );
		void setName(std::string name);
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

