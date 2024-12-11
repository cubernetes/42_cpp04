// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Dog::~Dog() { cout << ANSI_PUNCT "~" << *this << '\n'; delete _brain; }
Dog::Dog() : AAnimal("Dog"), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Dog" ANSI_PUNCT "() -> " << *this << '\n'; }
Dog::Dog(const string& type) : AAnimal(type), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Dog" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Dog::Dog(const char* type) : AAnimal(type), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Dog" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Dog::Dog(const string& type, const Brain& brain) : AAnimal(type), _brain(new Brain(brain)), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)), _id(_id_cntr++) { cout << ANSI_KWRD "Dog" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator (using copy-swap idiom)
Dog& Dog::operator=(Dog other) /* noexcept */ {
	cout << ANSI_KWRD "Dog" ANSI_PUNCT "& " ANSI_KWRD "Dog" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Dog::repr() const {
	stringstream out;
	out << ANSI_KWRD "Dog" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ", " << ::repr(*_brain) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Dog::swap(Dog& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_id, other._id);
	::swap(_type, other._type);
	::swap(_brain, other._brain);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Dog::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Dog& a, Dog& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Dog& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Dog::makeSound() const {
	cout << "BARKKKK BARK BARK ~woof~ BARKK!11!!!!1!1\n";
}

const Brain* Dog::getBrain() const { return _brain; }

unsigned int Dog::_id_cntr = 0;
