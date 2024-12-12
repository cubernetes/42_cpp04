// <GENERATED>
#pragma once /* Character.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "helper.hpp"
#include "ICharacter.hpp"

using std::string;
using std::ostream;

class Character : public ICharacter {
public:
	// <generated>
		~Character(); // destructor; consider virtual if it's a base class
		Character(); // default constructor
		explicit Character(const string&);
		Character(const string&, const AMateria*&, unsigned int); // serializing constructor
		Character(const Character&); // copy constructor
		Character& operator=(Character); // copy-assignment operator
		void swap(Character&); // copy-swap idiom
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string

		const string& getName() const /* override */;
		AMateria* const* get_inventory() const;
		unsigned int get_n_inventory_items() const;

		void setName(const string&);

		template <typename T>
		Character(const T& type, DeleteOverload = 0); // disallow accidental casting/conversion
	// </generated>
	
	void equip(AMateria*) /* override */;
	void unequip(int) /* override */;
	void use(int, ICharacter&) /* override */;
private:
	unsigned int _id;
	static unsigned int _id_cntr;
	static const unsigned int _inventory_size = 4;
	string _name;
	AMateria* _inventory[_inventory_size];
	unsigned int _n_inventory_items;
};

template <> inline string repr(const Character& value) { return value.repr(); }
void swap(Character&, Character&) /* noexcept */;
ostream& operator<<(ostream&, const Character&);
// </GENERATED>
