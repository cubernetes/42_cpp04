// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
MateriaSource::~MateriaSource() {
	cout << ANSI_PUNCT "~" << *this << '\n';
	for (unsigned int i = 0; i < _nLearned; ++i)
		delete _learnedMaterias[i];
}
MateriaSource::MateriaSource() : _learnedMaterias(), _nLearned(), _id(_id_cntr++) { cout << ANSI_KWRD "MateriaSource" ANSI_PUNCT "() -> " << *this << '\n'; }
// MateriaSource::MateriaSource(const AMateria*& learnedMaterias, unsigned int _nLearned) : _learnedMaterias(learnedMaterias), _nLearned(_nLearned), _id(_id_cntr++) { cout << *this << ANSI_PUNCT " -> " << *this << '\n'; }
MateriaSource::MateriaSource(const MateriaSource& other) : _nLearned(other._nLearned), _id(_id_cntr++) {
	cout << ANSI_KWRD "MateriaSource" ANSI_PUNCT "(" << ::repr(other) << ANSI_PUNCT ") -> " << *this << '\n';
	for (unsigned int i = 0; i < _nLearned; ++i) {
		delete _learnedMaterias[i];
		_learnedMaterias[i] = other._learnedMaterias[i]->clone();
	}
}

// Copy-assignment operator (using copy-swap idiom)
MateriaSource& MateriaSource::operator=(MateriaSource other) /* noexcept */ {
	cout << ANSI_KWRD "MateriaSource" ANSI_PUNCT "& " ANSI_KWRD "MateriaSource" ANSI_PUNCT "::" ANSI_FUNC "operator" ANSI_PUNCT "=(" << ::repr(other) << ANSI_PUNCT ")" ANSI_RST "\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
AMateria* const* MateriaSource::get_learnedMaterias() const { return _learnedMaterias; }
unsigned int MateriaSource::get_nLearned() const { return _nLearned; }

// Generated member functions
string MateriaSource::repr() const {
	stringstream out;
	out << ANSI_KWRD "MateriaSource" ANSI_PUNCT "(" << ::repr(_learnedMaterias, _nMaxMaterias) << ANSI_PUNCT ", " << ::repr(_nLearned) << ANSI_PUNCT ", " << ::repr(_id) << ANSI_PUNCT ")" ANSI_RST;
	return out.str();
}
void MateriaSource::swap(MateriaSource& other) /* noexcept */ {
	cout << ANSI_CMT "<Swapping *this:" ANSI_RST "\n";
	cout << *this << '\n';
	cout << ANSI_CMT "with the following object:" ANSI_RST "\n";
	cout << other << '\n';
	::swap(_learnedMaterias, other._learnedMaterias);
	::swap(_nLearned, other._nLearned);
	cout << ANSI_CMT "swap done>" ANSI_RST "\n";
}
MateriaSource::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(MateriaSource& a, MateriaSource& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const MateriaSource& other) { return os << static_cast<string>(other); }

// Keeping track of the instances
unsigned int MateriaSource::_id_cntr = 0;
// </GENERATED>

void MateriaSource::learnMateria(AMateria* materia) {
	if (_nLearned < _nMaxMaterias)
		_learnedMaterias[_nLearned++] = materia;
}

AMateria* MateriaSource::createMateria(const string& type) {
	for (unsigned int i(0); i < _nLearned; ++i) {
		if (type == _learnedMaterias[i]->getType())
			return _learnedMaterias[i]->clone();
	}
	return NULL;
}
