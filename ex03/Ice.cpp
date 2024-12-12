// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Ice::~Ice() { cout << ANSI_PUNCT "~" << *this << '\n'; }
Ice::Ice() : AMateria("ice"), _id(_id_cntr++) { cout << ANSI_KWRD "Ice" ANSI_PUNCT "() -> " << *this << '\n'; }
Ice::Ice(const string& type) : AMateria(type), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Ice::Ice(const Ice& other) : AMateria(other), _id(_id_cntr++) { cout << ANSI_KWRD "Ice" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator (using copy-swap idiom)
Ice& Ice::operator=(Ice other) /* noexcept */ {
	cout << ANSI_KWRD "Ice" ANSI_PUNCT "& " ANSI_KWRD "Ice" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Ice::repr() const {
	stringstream out;
	out << ANSI_KWRD "Ice" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Ice::swap(Ice& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_type, other._type);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Ice::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Ice& a, Ice& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Ice& other) { return os << static_cast<string>(other); }

// Keeping track of the instances
unsigned int Ice::_id_cntr = 0;
// </GENERATED>

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
	cout << "* shoots and ice bolt at " << target.getName() << "*\n";
}
