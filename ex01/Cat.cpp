// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Cat::~Cat() { cout << "~Cat()\n"; }
Cat::Cat() : Animal("Cat") { cout << "Cat()\n"; }
Cat::Cat(const string& type) : Animal(type) { cout << *this << '\n'; }
Cat::Cat(const Cat& other) : Animal(other) { cout << "Cat(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
Cat& Cat::operator=(Cat other) /* noexcept */ {
	cout << "Cat& Cat::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Cat::repr() const {
	stringstream out;
	out << "Cat(" << ::repr(_type) << ")";
	return out.str();
}
void Cat::swap(Cat& other) /* noexcept */ {
	::swap(_type, other._type);
}
Cat::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Cat& a, Cat& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Cat& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Cat::makeSound() const {
	cout << "MEOW MEOW MEO.. ME.. MEEE MEE LOOK AT MEE MEEEEOOW MEEOWWWW\n";
}
