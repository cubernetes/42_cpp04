// <GENERATED>
#include <iostream> /* cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "AMateria.hpp"
#include "repr.hpp"
#include "Character.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Character::~Character() {
	cout << ANSI_PUNCT "~" << *this << '\n';
	for (unsigned int i(0); i < _inventory_size; ++i) {
		if (_itemOwnerships[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
}
Character::Character() : _name("Anonymous"), _inventory(), _itemOwnerships(), _id(_id_cntr++) { cout << ANSI_KWRD "Character" ANSI_PUNCT "() -> " << *this << '\n'; }
Character::Character(const string& name) : _name(name), _inventory(), _itemOwnerships(), _id(_id_cntr++) { cout << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(name) << ANSI_PUNCT ") -> " << *this << '\n'; }
// Character::Character(const string& name, const AMateria*& inventory, unsigned int n_inventory_items) : _name(name), _inventory(inventory), _itemOwnerships(itemOwnerships), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Character::Character(const Character& other) : _name(other._name), _id(_id_cntr++) {
	cout << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n';
	for (unsigned int i = 0; i < other._inventory_size; ++i) {
		if (_itemOwnerships[i])
			delete _inventory[i];
		_inventory[i] = other._inventory[i]->clone();
		_itemOwnerships[i] = true;
	}
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

// Generated setters
void Character::setName(const string& value) { _name = value; }

// Generated member functions
string Character::repr() const {
	stringstream out;
	out << ANSI_KWRD "Character" ANSI_PUNCT "(" << ::repr(_name) << ANSI_PUNCT ", " << ::repr(_inventory, _inventory_size) << ANSI_PUNCT ", " << ::repr(_itemOwnerships, _inventory_size) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Character::swap(Character& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_name, other._name);
	::swap(_inventory, other._inventory);
	::swap(_itemOwnerships, other._itemOwnerships);
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
	for (unsigned int i = 0; i < _inventory_size; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			_itemOwnerships[i] = true;
			return;
		}
	}
	cout << "Can't equip, there are already 4 items in " << _name << "'s inventory\n";
}

void Character::borrow(AMateria* m) {
	for (unsigned int i = 0; i < _inventory_size; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			_itemOwnerships[i] = false;
			return;
		}
	}
	cout << "Can't borrow, there are already 4 items in " << _name << "'s inventory\n";
}

/* we're not managing the floor, either the caller manages the Materias themself,
 * or they make a floor class that manages the Materias. Character shouldn't worry */
void Character::unequip(unsigned int idx) {
	if (0 <= idx && idx < _inventory_size) {
		if (_itemOwnerships[idx]) {
			cout << "Cannot unequip object that belongs to you! What do you expect? A SingletonFloorManager class? Use give() if you want to transfer item ownership\n";
			return;
		} else if (_inventory[idx] == NULL) {
			// cout << "There's no item to unequip at index " << idx << " in " << _name << "'s inventory\n";
			return;
		}
		_inventory[idx] = NULL;
		_itemOwnerships[idx] = false;
	} else
		cout << "There's no inventory slot " << idx << " in " << _name << "'s inventory\n";
}

AMateria* Character::give(unsigned int idx) {
	if (0 <= idx && idx < _inventory_size) {
		if (!_itemOwnerships[idx]) {
			cout << "Cannot give object that doesn't belong to you! You wouldn't lend something that you yourself borrowed, right?\n";
			return NULL;
		} else if (_inventory[idx] == NULL) {
			// cout << "There's no item to unequip at index " << idx << " in " << _name << "'s inventory\n";
			return NULL;
		}
		AMateria* ret = _inventory[idx];
		_inventory[idx] = NULL;
		_itemOwnerships[idx] = false;
		return ret;
	} else
		cout << "There's no inventory slot " << idx << " in " << _name << "'s inventory\n";
	return NULL;
}

void Character::use(unsigned int idx, ICharacter& target) {
	if (0 <= idx && idx < _inventory_size) {
		if (_inventory[idx] == NULL) {
			cout << "There's no item to use at index " << idx << " in " << _name << "'s inventory\n";
			return;
		}
		_inventory[idx]->use(target);
	} else
		cout << "There's no inventory slot " << idx << " in " << _name << "'s inventory\n";
}
