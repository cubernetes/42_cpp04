// <GENERATED>
#pragma once /* Cure.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "AMateria.hpp"

using std::string;
using std::ostream;

class Cure : public AMateria {
public:
	// <generated>
		~Cure(); // destructor; consider virtual if it's a base class
		Cure(); // default constructor
		explicit Cure(const string&); // serializing constructor
		Cure(const Cure&); // copy constructor
		Cure& operator=(Cure); // copy-assignment operator
		void swap(Cure&); // copy-swap idiom
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string
	// </generated>

	AMateria* clone() const /* override */;
	void use(ICharacter& target) /* override */;
private:
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const Cure& value) { return value.repr(); }
void swap(Cure&, Cure&) /* noexcept */;
ostream& operator<<(ostream&, const Cure&);
// </GENERATED>
