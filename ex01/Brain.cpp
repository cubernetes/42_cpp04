// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Brain.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Brain::~Brain() { cout << "~Brain()\n"; }
Brain::Brain() : _ideas() { cout << "Brain()\n"; }
Brain::Brain(const string*& ideas) : _ideas(ideas) { cout << *this << '\n'; }
Brain::Brain(const Brain& other) : _ideas(other._ideas) { cout << "Brain(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
Brain& Brain::operator=(Brain other) /* noexcept */ {
	cout << "Brain& Brain::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
const string*& Brain::get_ideas() const { return _ideas; }

// Generated setters
void Brain::set_ideas(const string*& value) { _ideas = value; }

// Generated member functions
string Brain::repr() const {
	stringstream out;
	out << "Brain(" << ::repr(_ideas) << ")";
	return out.str();
}
void Brain::swap(Brain& other) /* noexcept */ {
	::swap(_ideas, other._ideas);
}
Brain::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Brain& a, Brain& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Brain& other) { return os << static_cast<string>(other); }
// </GENERATED>
