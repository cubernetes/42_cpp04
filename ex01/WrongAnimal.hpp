// <GENERATED>
#pragma once /* WrongAnimal.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */

using std::string;
using std::ostream;

class WrongAnimal {
public:
	// <generated>
	virtual ~WrongAnimal(); // consider virtual if it's a base class
	WrongAnimal();
	explicit WrongAnimal(const string&);
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=(WrongAnimal);
	void swap(WrongAnimal&);
	string repr() const;
	operator string() const;

	const string& getType() const;

	void setType(const string&);
	// </generated>
	
	void makeSound() const;
protected:
	string _type;
};

template <> inline string repr(const WrongAnimal& value) { return value.repr(); }
void swap(WrongAnimal&, WrongAnimal&) /* noexcept */;
ostream& operator<<(ostream&, const WrongAnimal&);
// </GENERATED>
