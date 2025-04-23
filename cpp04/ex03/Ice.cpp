#include "Ice.hpp"

Ice::Ice( void ){
	type = "ice";
}

Ice::Ice(std::string const & type){
	this->type = "ice";
}

Ice::Ice(const Ice & copy){
	*this = copy;
}

Ice &Ice::operator=(const Ice &src){
	std::cout << "Assigning an Ice to another doesn't make sense" << std::endl;
	return (*this);
}

Ice::~Ice( void ){}

AMateria *Ice::clone() const {
	AMateria *newAmateria = new Ice(*this);
	return newAmateria;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
        << std::endl;
}
