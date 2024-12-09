// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Animal.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Animal::~Animal() { cout << "~Animal()\n"; }
Animal::Animal() : _type("Generic Animal") { cout << "Animal()\n"; }
Animal::Animal(const string& type) : _type(type) { cout << *this << '\n'; }
Animal::Animal(const Animal& other) : _type(other._type) { cout << "Animal(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
Animal& Animal::operator=(Animal other) /* noexcept */ {
	cout << "Animal& Animal::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
const string& Animal::getType() const { return _type; }

// Generated setters
void Animal::setType(const string& value) { _type = value; }

// Generated member functions
string Animal::repr() const {
	stringstream out;
	out << "Animal(" << ::repr(_type) << ")";
	return out.str();
}
void Animal::swap(Animal& other) /* noexcept */ {
	::swap(_type, other._type);
}
Animal::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Animal& a, Animal& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Animal& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Animal::makeSound() const {
	cout << "<abstract animal noises>\n";
}
