// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "WrongAnimal.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
WrongAnimal::~WrongAnimal() { cout << "~WrongAnimal()\n"; }
WrongAnimal::WrongAnimal() : _type("Generic Wrong Animal") { cout << "WrongAnimal()\n"; }
WrongAnimal::WrongAnimal(const string& type) : _type(type) { cout << *this << '\n'; }
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) { cout << "WrongAnimal(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
WrongAnimal& WrongAnimal::operator=(WrongAnimal other) /* noexcept */ {
	cout << "WrongAnimal& WrongAnimal::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
const string& WrongAnimal::getType() const { return _type; }

// Generated setters
void WrongAnimal::setType(const string& value) { _type = value; }

// Generated member functions
string WrongAnimal::repr() const {
	stringstream out;
	out << "WrongAnimal(" << ::repr(_type) << ")";
	return out.str();
}
void WrongAnimal::swap(WrongAnimal& other) /* noexcept */ {
	::swap(_type, other._type);
}
WrongAnimal::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(WrongAnimal& a, WrongAnimal& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const WrongAnimal& other) { return os << static_cast<string>(other); }
// </GENERATED>

void WrongAnimal::makeSound() const {
	cout << "<abstract wrong-animal noises>\n";
}
