#include "Cat.hpp"

Cat::Cat( void ): Animal(){
	std::cout << "Default constructor Called (CAT)" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat( void ){
	delete brain;
}

Cat::Cat( const Cat &cat ): Animal(){
	std::cout << "Copy constructor called (CAT)" << std::endl;
	brain = new Brain(*cat.brain);
	type = cat.type;
}

Cat& Cat::operator=(const Cat &cat){
	if (this != &cat){
		type = cat.type;
		*brain = *cat.brain;
	}
	return (*this);
}

void	Cat::setType(const std::string _type){
	type = _type;
}

std::string	Cat::getType( void ){
	return (type);
}

Brain	*Cat::getBrain(void){
	return (this->brain);
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaouuuuuu" << std::endl;
}
