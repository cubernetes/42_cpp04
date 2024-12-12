// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Character.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Character::~Character() { cout << ANSI_PUNCT "~" << *this << '\n'; }
Character::Character() : _name("Anonymous"), _inventory(), _n_inventory_items(), _id(_id_cntr++) { cout << ANSI_KWRD "Character" ANSI_PUNCT "() -> " << *this << '\n'; }
Character::Character(string name) : _name(name), _inventory(), _n_inventory_items(), _id(_id_cntr++) { cout << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(name) << ANSI_PUNCT ") -> " << *this << '\n'; }
// Character::Character(const string& name, const AMateria*& inventory, unsigned int n_inventory_items) : _name(name), _inventory(inventory), _n_inventory_items(n_inventory_items), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Character::Character(const Character& other) : _name(other._name), _n_inventory_items(other._n_inventory_items), _id(_id_cntr++) {
	for (int i = 0; i < other._inventory_size; ++i)
		_inventory[i] = other._inventory[i];
	cout << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n';
}

// Copy-assignment operator (using copy-swap idiom)
Character& Character::operator=(Character other) /* noexcept */ {
	cout << ANSI_KWRD "Character" ANSI_PUNCT "& " ANSI_KWRD "Character" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
const string& Character::getName() const { return _name; }
AMateria* const* Character::get_inventory() const { return _inventory; }
unsigned int Character::get_n_inventory_items() const { return _n_inventory_items; }

// Generated setters
void Character::setName(const string& value) { _name = value; }

// Generated member functions
string Character::repr() const {
	stringstream out;
	out << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(_name) << ANSI_PUNCT ", " << ::repr(_inventory) << ANSI_PUNCT ", " << ::repr(_n_inventory_items) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Character::swap(Character& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_name, other._name);
	::swap(_inventory, other._inventory);
	::swap(_n_inventory_items, other._n_inventory_items);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Character::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Character& a, Character& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Character& other) { return os << static_cast<string>(other); }

// Keeping track of the instances
unsigned int Character::_id_cntr = 0;
// </GENERATED>

void Character::equip(AMateria* m) {
	if (_n_inventory_items <= _inventory_size) {
		_inventory[_n_inventory_items] = m;
		++_n_inventory_items;
	}
}
void Character::unequip(int idx) {
	if (0 <= idx && idx < _n_inventory_items) {
		while (idx < _inventory_size - 1 && _inventory[idx] != NULL) {
			_inventory[idx] = _inventory[idx + 1];
			++idx;
		}
		_inventory[idx] = NULL;
		--_n_inventory_items;
	}
}
void Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx < _n_inventory_items && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
}
