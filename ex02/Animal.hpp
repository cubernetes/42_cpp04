// <GENERATED>
#pragma once /* Animal.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */

using std::string;
using std::ostream;

class Animal {
public:
	// <generated>
	virtual ~Animal(); // consider virtual if it's a base class
	Animal();
	explicit Animal(const string&);
	explicit Animal(const char*);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	void swap(Animal&);
	string repr() const;
	operator string() const;

	const string& getType() const;

	void setType(const string&);
	// </generated>
	
	virtual void makeSound() const = 0;

	// ######### In the animal class, we actually want to allow constructors with differing types!
	// ######### Reason being: an animal can be constructed be a derived type!
	// template <typename T>
	// Animal(const T& type, DeleteOverload = 0); // disallow accidental casting/conversion
protected:
	string _type;
};

template <> inline string repr(const Animal& value) { return value.repr(); }
void swap(Animal&, Animal&) /* noexcept */;
ostream& operator<<(ostream&, const Animal&);
// </GENERATED>
