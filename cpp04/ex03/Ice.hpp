#pragma once

#include "Amateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice & copy);
		Ice &operator=(const Ice &src);
		virtual ~Ice();
		
		virtual AMateria* clone() const;
		virtual void	use(ICharacter& target);

	private:

};
