// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Cure::~Cure() { cout << ANSI_PUNCT "~" << *this << '\n'; }
Cure::Cure() : AMateria("cure"), _id(_id_cntr++) { cout << ANSI_KWRD "Cure" ANSI_PUNCT "() -> " << *this << '\n'; }
Cure::Cure(const string& type) : AMateria(type), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Cure::Cure(const Cure& other) : AMateria(other), _id(_id_cntr++) { cout << ANSI_KWRD "Cure" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator (using copy-swap idiom)
Cure& Cure::operator=(Cure other) /* noexcept */ {
	cout << ANSI_KWRD "Cure" ANSI_PUNCT "& " ANSI_KWRD "Cure" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	// ::swap(*this, other); // subject says "NO"
	return *this;
}

// Generated member functions
string Cure::repr() const {
	stringstream out;
	out << ANSI_KWRD "Cure" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Cure::swap(Cure& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_type, other._type);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Cure::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Cure& a, Cure& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Cure& other) { return os << static_cast<string>(other); }

// Keeping track of the instances
unsigned int Cure::_id_cntr = 0;
// </GENERATED>

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
	cout << "* heals " << target.getName() << "'s wounds *\n";
}
