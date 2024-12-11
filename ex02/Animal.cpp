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
Animal::~Animal() { cout << ANSI_PUNCT "~" << *this << '\n'; }
Animal::Animal() : _type("Generic Animal") { cout << ANSI_KWRD "Animal" ANSI_PUNCT "() -> " << *this << '\n'; }
Animal::Animal(const string& type) : _type(type) { cout << ANSI_KWRD "Animal" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Animal::Animal(const char* type) : _type(type) { cout << ANSI_KWRD "Animal" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Animal::Animal(const Animal& other) : _type(other._type) { cout << ANSI_KWRD "Animal" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator (using copy-swap idiom)
Animal& Animal::operator=(const Animal& other) /* noexcept */ {
	cout << ANSI_KWRD "Animal" ANSI_PUNCT "& " ANSI_KWRD "Animal" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_KWRD "=(" << ::repr(other) << ANSI_KWRD ")" ANSI_RST "\n";
	_type = other._type;
	return *this;
}

// Generated getters
const string& Animal::getType() const { return _type; }

// Generated setters
void Animal::setType(const string& value) { _type = value; }

// Generated member functions
string Animal::repr() const {
	stringstream out;
	out << ANSI_KWRD "Animal" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Animal::swap(Animal& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_type, other._type);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Animal::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Animal& a, Animal& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Animal& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Animal::makeSound() const {
	cout << "<abstract animal noises>\n";
}
