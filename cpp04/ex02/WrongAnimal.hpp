#pragma once
#include <iostream>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &animal);
		
		std::string getType( void )const;
		virtual void	makeSound( void ) const;

	protected:
		std::string type;
};

