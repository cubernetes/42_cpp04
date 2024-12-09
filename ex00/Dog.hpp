// <GENERATED>
#pragma once /* Dog.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "Animal.hpp"

using std::string;
using std::ostream;

class Dog : public Animal {
public:
	// <generated>
	~Dog(); // consider virtual if it's a base class
	Dog();
	explicit Dog(const string&);
	Dog(const Dog&);
	Dog& operator=(Dog);
	void swap(Dog&);
	string repr() const;
	operator string() const;
	// </generated>

	void makeSound() const /* override */;
};

template <> inline string repr(const Dog& value) { return value.repr(); }
void swap(Dog&, Dog&) /* noexcept */;
ostream& operator<<(ostream&, const Dog&);
// </GENERATED>
