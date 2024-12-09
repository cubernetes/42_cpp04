// <GENERATED>
#pragma once /* WrongCawt.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "WrongAnimal.hpp"

using std::string;
using std::ostream;

class WrongCat : public WrongAnimal {
public:
	// <generated>
	~WrongCat(); // consider virtual if it's a base class
	WrongCat();
	explicit WrongCat(const string&);
	WrongCat(const WrongCat&);
	WrongCat& operator=(WrongCat);
	void swap(WrongCat&);
	string repr() const;
	operator string() const;
	// </generated>

	void makeSound() const /* override */;
};

template <>
inline string repr(const WrongCat& value) {
	return value.repr();
}

void swap(WrongCat&, WrongCat&) /* noexcept */;
ostream& operator<<(ostream&, const WrongCat&);
// </GENERATED>
