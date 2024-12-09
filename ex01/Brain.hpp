// <GENERATED>
#pragma once /* Brain.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */

using std::string;
using std::ostream;

class Brain {
public:
	// partly <generated>
	~Brain(); // consider virtual if it's a base class
	Brain();
	explicit Brain(const string*&); // TODO IS THIS RIGHT?
	Brain(const Brain&);
	Brain& operator=(Brain);
	void swap(Brain&);
	string repr() const;
	operator string() const;

	const string& get_ideas(unsigned int idx) const;

	void set_ideas(unsigned int idx, const string&);
	// </generated>
private:
	static const int _n_ideas = 100;
	string _ideas[_n_ideas];
};

// TODO: ADD REPR FOR POINTER AND ARRAY TYPES
template <> inline string repr(const Brain& value) { return value.repr(); }
void swap(Brain&, Brain&) /* noexcept */;
ostream& operator<<(ostream&, const Brain&);
// </GENERATED>
