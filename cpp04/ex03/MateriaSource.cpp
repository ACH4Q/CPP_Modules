#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        this->_templates[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._templates[i])
            this->_templates[i] = src._templates[i]->clone();
        else
            this->_templates[i] = 0;
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete this->_templates[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->_templates[i];
            this->_templates[i] = 0;
            if (other._templates[i])
                this->_templates[i] = other._templates[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!this->_templates[i]) {
            this->_templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_templates[i] && this->_templates[i]->getType() == type) {
            return this->_templates[i]->clone();
        }
    }
    return 0;
}