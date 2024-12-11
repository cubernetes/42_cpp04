// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Cat::~Cat() { cout << ANSI_PUNCT "~" << *this << '\n'; delete _brain; }
Cat::Cat() : AAnimal("Cat"), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Cat" ANSI_PUNCT "() -> " << *this << '\n'; }
Cat::Cat(const string& type) : AAnimal(type), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Cat" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Cat::Cat(const char* type) : AAnimal(type), _brain(new Brain()), _id(_id_cntr++) { cout << ANSI_KWRD "Cat" ANSI_PUNCT "(" << ::repr(type) << ANSI_PUNCT ") -> " << *this << '\n'; }
Cat::Cat(const string& type, const Brain& brain) : AAnimal(type), _brain(new Brain(brain)), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)), _id(_id_cntr++) { cout << ANSI_KWRD "Cat" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n'; }

// Copy-assignment operator (using copy-swap idiom)
Cat& Cat::operator=(Cat other) /* noexcept */ {
	cout << ANSI_KWRD "Cat" ANSI_PUNCT "& " ANSI_KWRD "Cat" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Cat::repr() const {
	stringstream out;
	out << ANSI_KWRD "Cat" ANSI_PUNCT "(" << ::repr(_type) << ANSI_PUNCT ", " << ::repr(*_brain) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Cat::swap(Cat& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_id, other._id);
	::swap(_type, other._type);
	::swap(_brain, other._brain);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Cat::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Cat& a, Cat& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Cat& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Cat::makeSound() const {
	cout << "MEOW MEOW MEO.. ME.. MEEE MEE LOOK AT MEE MEEEEOOW MEEOWWWW\n";
}

const Brain* Cat::getBrain() const { return _brain; }

unsigned int Cat::_id_cntr = 0;
