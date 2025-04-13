#pragma once
#include <iostream>

class Animal{
	public:
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &animal);
		
		std::string getType( void )const;
		virtual void	makeSound( void ) const = 0;

	protected:
		Animal();
		std::string type;
};
