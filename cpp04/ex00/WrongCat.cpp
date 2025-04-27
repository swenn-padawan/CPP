#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal(){
	std::cout << "Default constructor Called (WRONG CAT)" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat( void ){}

WrongCat::WrongCat( const WrongCat &cat ): WrongAnimal(){
	std::cout << "Copy constructor called (WRONG CAT)" << std::endl;
	type = cat.type;
}

WrongCat& WrongCat::operator=(const WrongCat &cat){
	type = cat.type;
	return (*this);
}

void	WrongCat::setType(const std::string _type){
	type = _type;
}

std::string	WrongCat::getType( void ){
	return (type);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Hmmmmm im not a cat" << std::endl;
}
