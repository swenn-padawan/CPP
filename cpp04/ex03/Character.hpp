#pragma once

#include "Interface.hpp"
#include "Amateria.hpp"

class Character: public ICharacter{
	public:
		Character();
		Character(std::string const & name);
		Character(const Character & copy);
		Character &operator=(const Character &src);
		virtual ~Character();

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		std::string	getName(void) const;
	private:
		std::string name;
		AMateria*	inventory[4];
};
