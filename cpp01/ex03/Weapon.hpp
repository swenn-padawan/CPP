#pragma once
#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string	getType(void);
		void				setType(std::string type);
};
