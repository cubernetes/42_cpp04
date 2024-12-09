// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Animal.hpp"
#include "Dog.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Dog::~Dog() { cout << "~Dog()\n"; }
Dog::Dog() : Animal("Dog") { cout << "Dog()\n"; }
Dog::Dog(const string& type) : Animal(type) { cout << *this << '\n'; }
Dog::Dog(const Dog& other) : Animal(other) { cout << "Dog(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
Dog& Dog::operator=(Dog other) /* noexcept */ {
	cout << "Dog& Dog::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Dog::repr() const {
	stringstream out;
	out << "Dog(" << ::repr(_type) << ")";
	return out.str();
}
void Dog::swap(Dog& other) /* noexcept */ {
	::swap(_type, other._type);
}
Dog::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Dog& a, Dog& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Dog& other) { return os << static_cast<string>(other); }
// </GENERATED>

void Dog::makeSound() const {
	cout << "BARKKKK BARK BARK ~woof~ BARKK!11!!!!1!1\n";
}
