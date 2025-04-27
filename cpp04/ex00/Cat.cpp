#include "Cat.hpp"

Cat::Cat( void ): Animal(){
	std::cout << "Default constructor Called (CAT)" << std::endl;
	type = "Cat";
}

Cat::~Cat( void ){}

Cat::Cat( const Cat &cat ): Animal(){
	std::cout << "Copy constructor called (CAT)" << std::endl;
	type = cat.type;
}

Cat& Cat::operator=(const Cat &cat){
	type = cat.type;
	return (*this);
}

void	Cat::setType(const std::string _type){
	type = _type;
}

std::string	Cat::getType( void ){
	return (type);
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaouuuuuu" << std::endl;
}
