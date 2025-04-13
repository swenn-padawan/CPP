#pragma once
#include <iostream>

class Animal{
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &animal);
		
		std::string getType( void )const;
		virtual void	makeSound( void ) const;

	protected:
		std::string type;
};
