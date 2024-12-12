// <GENERATED>
#include <iostream> /* std::cout, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "AAnimal.hpp"

using std::cout;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
AAnimal::~AAnimal() { cout << ANSI_PUNCT "~" << *this << '\n'; }
AAnimal::AAnimal() : _type("Generic AAnimal") { cout << ANSI_KWRD "AAnimal" ANSI_PUNCT "() -> " << *this << '\n'; }
AAnimal::AAnimal(const string& type) : _type(type) { cout << ANSI_KWRD "AAnimal" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
AAnimal::AAnimal(const char* type) : _type(type) { cout << ANSI_KWRD "AAnimal" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
AAnimal::AAnimal(const AAnimal& other) : _type(other._type) { cout << ANSI_KWRD "AAnimal" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) /* noexcept */ {
	cout << ANSI_KWRD "AAnimal" ANSI_PUNCT "& " ANSI_KWRD "AAnimal" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_KWRD "=(" << ::repr(other) << ANSI_KWRD ")" ANSI_RST "\n";
	_type = other._type;
	return *this;
}

// Generated getters
const string& AAnimal::getType() const { return _type; }

// Generated setters
void AAnimal::setType(const string& value) { _type = value; }

// Generated member functions
string AAnimal::repr() const {
	stringstream out;
	out << ANSI_KWRD "AAnimal" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
AAnimal::operator string() const { return ::repr(*this); }

// Generated free functions
ostream& operator<<(ostream& os, const AAnimal& other) { return os << static_cast<string>(other); }
// </GENERATED>

void AAnimal::makeSound() const {
	cout << "<abstract animal noises>\n";
}
