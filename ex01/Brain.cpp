// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <stdexcept>
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
Brain::~Brain() { cout << ANSI_PUNCT "~" << *this << '\n'; }
Brain::Brain() : _ideas() { cout << ANSI_KWRD "Brain" ANSI_PUNCT "() -> " << *this << '\n'; } // value-init _ideas, zeroing it
// Brain::Brain(const string* ideas) : _ideas{ideas} { cout << *this << '\n'; }
Brain::Brain(const Brain& other) {
	cout << ANSI_KWRD "Brain" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n';
	for (int i = 0; i < _n_ideas; ++i)
		_ideas[i] = other._ideas[i];
}

// Copy-assignment operator (using copy-swap idiom)
Brain& Brain::operator=(Brain other) /* noexcept */ {
	cout << ANSI_KWRD "Brain" ANSI_PUNCT "& " ANSI_KWRD "Brain" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_KWRD "=(" << ::repr(other) << ANSI_KWRD ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated member functions
string Brain::repr() const {
	stringstream out;
	out << ANSI_KWRD "Brain" ANSI_PUNCT "(" << ::repr(_ideas, _n_ideas) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void Brain::swap(Brain& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_ideas, other._ideas); // HEHE LOL: https://cplusplus.github.io/LWG/issue809
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
Brain::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Brain& a, Brain& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Brain& other) { return os << static_cast<string>(other); }
// </GENERATED>

const string Brain::_empty_thought = "Empty thought";

void Brain::delete_idea(unsigned int idx) {
	if (idx >= _n_ideas) throw std::domain_error("Can't delete thought at index " + ::repr(idx));
	_ideas[idx] = "";
}

const string& Brain::get_idea(unsigned int idx) const {
	if (idx >= _n_ideas) throw std::domain_error("Can't get thought at index " + ::repr(idx));
	return _ideas[idx].empty() ? _ideas[idx] : _empty_thought;
}

void Brain::set_idea(unsigned int idx, const string& value) {
	if (idx >= _n_ideas) throw std::domain_error("Can't set thought at index " + ::repr(idx));
	_ideas[idx] = value;
}
