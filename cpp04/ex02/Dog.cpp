#include "Dog.hpp"

Dog::Dog( void ): Animal(){
	std::cout << "Default constructor Called (DOG)" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog( void ){
	delete brain;
}

Dog::Dog( const Dog &dog ): Animal(){
	std::cout << "Copy constructor called (DOG)" << std::endl;
	brain = new Brain(*dog.brain);
	type = dog.type;
}

Dog& Dog::operator=(const Dog &dog){
	type = dog.type;
	*brain = *dog.brain;
	return (*this);
}

void	Dog::setType(const std::string _type){
	type = _type;
}

std::string	Dog::getType( void ){
	return (type);
}

Brain*	Dog::getBrains(){
	return (this->brain);
}

void	Dog::makeSound( void ) const {
	std::cout << "Waf Waf" << std::endl;
}
