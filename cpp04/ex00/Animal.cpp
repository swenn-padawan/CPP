#include "Animal.hpp"

Animal::Animal( void ){
	std::cout << "Default constructor Called (ANIMAL)" << std::endl;
	type = "Animal";
}

Animal::~Animal( void ){}

Animal::Animal( const Animal &animal ){
	std::cout << "Copy constructor called (ANIMAL)" << std::endl;
	type = animal.type;
}

Animal& Animal::operator=(const Animal &animal){
	type = animal.type;
	return (*this);
}

std::string	Animal::getType( void ) const{
	return (type);
}

void	Animal::makeSound( void ) const {
	std::cout << "This Animal make no sound !" << std::endl;
}
