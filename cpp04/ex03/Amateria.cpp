#include "Amateria.hpp"

AMateria::AMateria( void ){
	type = "unknown";
}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

AMateria::AMateria(const AMateria & copy){
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &src){
	this->type = src.type;
	return (*this);
}

AMateria::~AMateria( void ){}

std::string const &AMateria::getType( void ) const {
	return (this->type);
}

void	AMateria::setType(const std::string _type){
	this->type = _type;
}

