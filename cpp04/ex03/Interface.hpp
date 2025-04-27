
#pragma once

#include <iostream>
#include "MateriaSource.hpp"

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

	protected:
		std::string type;
};


class IMateriaSource
{
	private:
		AMateria* materias[4];

	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource& other);
		IMateriaSource& operator=(const IMateriaSource& other);
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};
