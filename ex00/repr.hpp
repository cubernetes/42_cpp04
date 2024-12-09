// <GENERATED>
#pragma once /* repr.hpp */

#include <sstream> /* std::ostringstream */
#include <string> /* std::string */

using std::string;

// generic template, works for ints, floats, and some other fundamental types
// repr should be specialized or overridden for custom classes
template <typename T>
inline string repr(const T& value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

// repr template specializations
template <>
inline string repr(const string& value) {
	return "std::string(\"" + value + "\")";
}

template <>
inline string repr(const char* const& value) {
	return string("\"") + value + "\"";
}

template <>
inline string repr(const char& value) {
	return string("'") + value + "'";
}
// </GENERATED>
