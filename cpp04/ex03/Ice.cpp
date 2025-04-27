#include "Ice.hpp"
#include "Amateria.hpp"

Ice::Ice( void ): AMateria(){
	type = "ice";
}

Ice::Ice(const Ice & copy): AMateria(){
	*this = copy;
}

Ice &Ice::operator=(const Ice &src){
	std::cout << "Assigning an Ice to another doesn't make sense" << std::endl;
	(void)src;
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
