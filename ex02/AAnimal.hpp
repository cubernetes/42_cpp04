// <GENERATED>
#pragma once /* AAnimal.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */

using std::string;
using std::ostream;

class AAnimal {
public:
	// <generated>
	virtual ~AAnimal(); // consider virtual if it's a base class
	AAnimal();
	explicit AAnimal(const string&);
	explicit AAnimal(const char*);
	AAnimal(const AAnimal&);
	AAnimal& operator=(const AAnimal&);
	string repr() const;
	operator string() const;

	const string& getType() const;

	void setType(const string&);
	// </generated>
	
	virtual void makeSound() const = 0;

	// ######### In the animal class, we actually want to allow constructors with differing types!
	// ######### Reason being: an animal can be constructed be a derived type!
	// template <typename T>
	// AAnimal(const T& type, DeleteOverload = 0); // disallow accidental casting/conversion
protected:
	string _type;
};

template <> inline string repr(const AAnimal& value) { return value.repr(); }
ostream& operator<<(ostream&, const AAnimal&);
// </GENERATED>
