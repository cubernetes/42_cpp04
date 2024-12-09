// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
WrongCat::~WrongCat() { cout << "~WrongCat()\n"; }
WrongCat::WrongCat() : WrongAnimal("WrongCat") { cout << "WrongCat()\n"; }
WrongCat::WrongCat(const string& type) : WrongAnimal(type) { cout << *this << '\n'; }
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) { cout << "WrongCat(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
WrongCat& WrongCat::operator=(WrongCat other) /* noexcept */ {
	cout << "WrongCat& WrongCat::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string WrongCat::repr() const {
	stringstream out;
	out << "WrongCat(" << ::repr(_type) << ")";
	return out.str();
}
void WrongCat::swap(WrongCat& other) /* noexcept */ {
	::swap(_type, other._type);
}
WrongCat::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(WrongCat& a, WrongCat& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const WrongCat& other) { return os << static_cast<string>(other); }
// </GENERATED>

void WrongCat::makeSound() const {
	cout << "MEOW MEOW MEO.. ME.. MEEE MEE LOOK AT MEE MEEEEOOW MEEOWWWW\n";
}
