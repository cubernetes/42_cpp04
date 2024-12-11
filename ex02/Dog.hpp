// <GENERATED>
#pragma once /* Dog.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "helper.hpp"

using std::string;
using std::ostream;

class Dog : public AAnimal {
public:
	// <generated>
	~Dog(); // consider virtual if it's a base class
	Dog();
	explicit Dog(const string&);
	explicit Dog(const char*);
	Dog(const string&, const Brain&);
	Dog(const Dog&);
	Dog& operator=(Dog);
	void swap(Dog&);
	string repr() const;
	operator string() const;
	// </generated>

	void makeSound() const /* override */;
	const Brain* getBrain() const;

	template <typename T>
	Dog(const T& type, DeleteOverload = 0); // disallow accidental casting/conversion
private:
	Brain* _brain;
	unsigned int _id;
	static unsigned int _id_cntr;
};

template <> inline string repr(const Dog& value) { return value.repr(); }
void swap(Dog&, Dog&) /* noexcept */;
ostream& operator<<(ostream&, const Dog&);
// </GENERATED>
