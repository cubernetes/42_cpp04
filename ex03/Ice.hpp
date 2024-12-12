// <GENERATED>
#pragma once /* Ice.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "helper.hpp"
#include "AMateria.hpp"

using std::string;
using std::ostream;

class Ice : public AMateria {
public:
	// <generated>
		~Ice(); // destructor; consider virtual if it's a base class
		Ice(); // default constructor
		explicit Ice(const string&); // serializing constructor
		Ice(const Ice&); // copy constructor
		Ice& operator=(Ice); // copy-assignment operator
		void swap(Ice&); // copy-swap idiom
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string

		template <typename T>
		Ice(const T& type, DeleteOverload = 0); // disallow accidental casting/conversion
	// </generated>

	AMateria* clone() const /* override */;
	void use(ICharacter& target) /* override */;
private:
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const Ice& value) { return value.repr(); }
void swap(Ice&, Ice&) /* noexcept */;
ostream& operator<<(ostream&, const Ice&);
// </GENERATED>
