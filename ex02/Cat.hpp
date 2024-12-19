// <GENERATED>
#pragma once /* Cat.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "AAnimal.hpp"
#include "Brain.hpp"

using std::string;
using std::ostream;

class Cat : public AAnimal {
public:
	// <generated>
	~Cat(); // consider virtual if it's a base class
	Cat();
	explicit Cat(const string&);
	explicit Cat(const char*);
	Cat(const string&, const Brain&);
	Cat(const Cat&);
	Cat& operator=(Cat);
	void swap(Cat&);
	string repr() const;
	operator string() const;
	// </generated>

	void makeSound() const /* override */;
	const Brain* getBrain() const;
private:
	Brain* _brain;
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const Cat& value) { return value.repr(); }
void swap(Cat&, Cat&) /* noexcept */;
ostream& operator<<(ostream&, const Cat&);
// </GENERATED>
