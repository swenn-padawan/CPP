
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (materias[i])
                delete materias[i];
        }
        for (int i = 0; i < 4; ++i)
        {
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        if (materias[i])
            delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] == NULL)
        {
            materias[i] = m;
            std::cout << "Materia learned!" << std::endl;
            return;
        }
    }
    std::cout << "No available slots to learn a new Materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    std::cout << "Materia type " << type << " not found!" << std::endl;
    return NULL;
}
