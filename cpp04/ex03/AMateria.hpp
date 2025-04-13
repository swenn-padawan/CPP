#pragma once

#include "ICharacter.hpp"
#include <iostream>

class AMateria{
	public:
		AMateria(std::string const & type);

		std::string const & getType() const; //return the AMateria type.
		
		virtual AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);
	protected:

};
