// <GENERATED>
#include <iostream> /* std::cout, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "AMateria.hpp"

using std::cout;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
AMateria::~AMateria() { cout << ANSI_PUNCT "~" << *this << '\n'; }
AMateria::AMateria() : _type("Unformed Matter") { cout << ANSI_KWRD "AMateria" ANSI_PUNCT "() -> " << *this << '\n'; }
AMateria::AMateria(const string& type) : _type(type) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
AMateria::AMateria(const AMateria& other) : _type(other._type) { cout << ANSI_KWRD "AMateria" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator
AMateria& AMateria::operator=(const AMateria& other) /* noexcept */ {
	cout << ANSI_KWRD "AMateria" ANSI_PUNCT "& " ANSI_KWRD "AMateria" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	_type = other._type;
	return *this;
}

// Generated getters
const string& AMateria::getType() const { return _type; }

// Generated setters
void AMateria::setType(const string& value) { _type = value; }

// Generated member functions
string AMateria::repr() const {
	stringstream out;
	out << ANSI_KWRD "AMateria" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
AMateria::operator string() const { return ::repr(*this); }

// Generated free functions
ostream& operator<<(ostream& os, const AMateria& other) { return os << static_cast<string>(other); }
// </GENERATED>
