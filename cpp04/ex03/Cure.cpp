#include "Cure.hpp"
#include "Amateria.hpp"

Cure::Cure( void ): AMateria(){
	type = "cure";
}

Cure::Cure(const Cure & copy): AMateria(){
	*this = copy;
}

Cure &Cure::operator=(const Cure &src){
	std::cout << "Assigning an Cure to another doesn't make sense" << std::endl;
	(void)src;
	return (*this);
}

Cure::~Cure( void ){}

AMateria *Cure::clone() const {
	AMateria *newAmateria = new Cure(*this);
	return newAmateria;
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds" << " *"
        << std::endl;
}
