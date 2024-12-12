// <GENERATED>
#pragma once /* AMateria.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "ICharacter.hpp"
class ICharacter;

using std::string;
using std::ostream;

class AMateria {
public:
	// <generated>
		virtual ~AMateria(); // destructor; consider virtual if it's a base class
		AMateria(); // default constructor
		explicit AMateria(const string&); // serializing constructor
		AMateria(const AMateria&); // copy constructor
		AMateria& operator=(const AMateria&); // copy-assignment operator
		string repr() const; // return string-serialized version of the object
		operator string() const; // convert object to string

		const string& getType() const;

		void setType(const string&);
	// </generated>
	
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
protected:
	string _type;
};

template <> inline string repr(const AMateria& value) { return value.repr(); }
ostream& operator<<(ostream&, const AMateria&);
// </GENERATED>
