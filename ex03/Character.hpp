// <GENERATED>
#pragma once /* Character.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "AMateria.hpp"
#include "repr.hpp" /* repr<T> */
#include "ICharacter.hpp"

using std::string;
using std::ostream;

class Character : public ICharacter {
public:
	// <generated>
		~Character(); // destructor; consider virtual if it's a base class
		Character(); // default constructor
		explicit Character(const string&);
		// Character(const string&, const AMateria*&, unsigned int); // serializing constructor
		Character(const Character&); // copy constructor
		Character& operator=(Character); // copy-assignment operator
		void swap(Character&); // copy-swap idiom
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string

		const string& getName() const /* override */;
		AMateria* const* get_inventory() const;
		unsigned int get_n_inventory_items() const;

		void setName(const string&);
	// </generated>
	
	void equip(AMateria*) /* override, equip item in an owning fashion */;
	void borrow(AMateria*); /* equip item without managing it, this could be solved via unique_ptr or smth */

	void unequip(unsigned int) /* override, unequip item that doesn't belong to you */;
	AMateria* give(unsigned int) /* transfer ownership of item that belongs to you */;

	void use(unsigned int, ICharacter&) /* override */;
private:
	static const unsigned int _inventory_size = 4;
	string _name;
	AMateria* _inventory[_inventory_size];
	bool _itemOwnerships[_inventory_size];
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const Character& value) { return value.repr(); }
void swap(Character&, Character&) /* noexcept */;
ostream& operator<<(ostream&, const Character&);
// </GENERATED>
