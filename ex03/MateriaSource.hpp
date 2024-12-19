// <GENERATED>
#pragma once /* MateriaSource.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

using std::string;
using std::ostream;

class MateriaSource : public IMateriaSource {
public:
	// <generated>
		~MateriaSource(); // destructor; consider virtual if it's a base class
		MateriaSource(); // default constructor
		// MateriaSource(const AMateria*&, unsigned int); // serializing constructor
		MateriaSource(const MateriaSource&); // copy constructor
		MateriaSource& operator=(MateriaSource); // copy-assignment operator
		void swap(MateriaSource&); // copy-swap idiom
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string

		AMateria* const* get_learnedMaterias() const;
		unsigned int get_nLearned() const;
	// </generated>
	
	void learnMateria(AMateria*);
	AMateria* createMateria(const string& type);
private:
	static const unsigned int _nMaxMaterias = 4;
	AMateria* _learnedMaterias[_nMaxMaterias];
	unsigned int _nLearned;
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const MateriaSource& value) { return value.repr(); }
void swap(MateriaSource&, MateriaSource&) /* noexcept */;
ostream& operator<<(ostream&, const MateriaSource&);
// </GENERATED>
