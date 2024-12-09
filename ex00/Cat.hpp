// <GENERATED>
#pragma once /* Cat.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "Animal.hpp"

using std::string;
using std::ostream;

class Cat : public Animal {
public:
	// <generated>
	~Cat(); // consider virtual if it's a base class
	Cat();
	explicit Cat(const string&);
	Cat(const Cat&);
	Cat& operator=(Cat);
	void swap(Cat&);
	string repr() const;
	operator string() const;
	// </generated>

	void makeSound() const /* override */;
};

template <> inline string repr(const Cat& value) { return value.repr(); }
void swap(Cat&, Cat&) /* noexcept */;
ostream& operator<<(ostream&, const Cat&);
// </GENERATED>
