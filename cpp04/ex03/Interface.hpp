
#pragma once

#include <iostream>

class AMateria;

class ICharacter{
	public:
		ICharacter();
		ICharacter(const ICharacter& copy);
		virtual ~ICharacter() {}
		virtual ICharacter &operator=(const ICharacter &src);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};


class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
