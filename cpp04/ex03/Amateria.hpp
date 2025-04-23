#pragma once

#include "Interface.hpp"

class AMateria{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & copy);
		AMateria &operator=(const AMateria &src);
		virtual ~AMateria();

		std::string const & getType() const; //return the AMateria type.
		void				setType(const std::string type);
 
		virtual AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);
	protected:
		std::string type;
};
