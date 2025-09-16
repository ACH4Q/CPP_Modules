// Character.hpp
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _inventory[4];

    public:

        Character(std::string const & name);
        Character(const Character &src);
        ~Character();
        Character &operator=(const Character &other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int id);
        void use(int id, ICharacter& target);
};

#endif