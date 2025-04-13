#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){
	std::cout << "Default constructor Called (WRONG ANIMAL)" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal( void ){}

WrongAnimal::WrongAnimal( const WrongAnimal &animal ){
	std::cout << "Copy constructor called (WRONG ANIMAL)" << std::endl;
	type = animal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &animal){
	type = animal.type;
	return (*this);
}

std::string	WrongAnimal::getType( void ) const{
	return (type);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "This WrongAnimal make no sound !" << std::endl;
}
