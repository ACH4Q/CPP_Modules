#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &other)
{
    if (this != &other) {}
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}