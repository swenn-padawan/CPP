#include "Interface.hpp"

IMateriaSource::IMateriaSource()
{
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
}

IMateriaSource::~IMateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i])
            delete materias[i];
    }
}

IMateriaSource::IMateriaSource(const IMateriaSource& src)
{
    for (int i = 0; i < 4; ++i)
    {
        if (src.materias[i])
            materias[i] = src.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (materias[i])
                delete materias[i];

            if (src.materias[i])
                materias[i] = src.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

void IMateriaSource::learnIMateria(IMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] == NULL)
        {
            materias[i] = m;
            return;
        }
    }
    std::cout << "IMateriaSource: Inventory full!" << std::endl;
}

IMateria* IMateriaSource::createIMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
