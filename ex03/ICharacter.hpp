#pragma once /* ICharacter.hpp */

#include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(unsigned int idx) = 0;
		virtual void use(unsigned int idx, ICharacter& target) = 0;

		virtual void borrow(AMateria* m) = 0; /* subject is stupid */
		virtual AMateria* give(unsigned int idx) = 0;
};
