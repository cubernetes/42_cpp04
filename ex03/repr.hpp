// <GENERATED>
#pragma once /* repr.hpp */

#include <sstream> /* std::ostringstream */
#include <string> /* std::string */

#define ANSI_CSI "\x1b\x5b"
#define ANSI_FG ANSI_CSI "48;2;41;41;41" "m"
#define ANSI_RST_FR ANSI_CSI "0" "m"
#define ANSI_RST    ANSI_CSI "0" "m" ANSI_FG
#define ANSI_STR    ANSI_FG ANSI_CSI "38;2;184;187;38"  "m"
#define ANSI_CHR    ANSI_FG ANSI_CSI "38;2;211;134;155" "m"
#define ANSI_KWRD   ANSI_FG ANSI_CSI "38;2;250;189;47"  "m"
#define ANSI_PUNCT  ANSI_FG ANSI_CSI "38;2;254;128;25"  "m"
#define ANSI_FUNC   ANSI_FG ANSI_CSI "38;2;184;187;38"  "m"
#define ANSI_NUM    ANSI_FG ANSI_CSI "38;2;211;134;155" "m"
#define ANSI_VAR    ANSI_FG ANSI_CSI "38;2;235;219;178" "m"
#define ANSI_PARAM  ANSI_FG ANSI_CSI "38;2;142;192;124" "m"
#define ANSI_CMT    ANSI_FG ANSI_CSI "38;2;146;131;116" "m"

using std::string;

// generic template, works for ints, floats, and some other fundamental types
// repr should be specialized or overridden for custom classes
template <typename T>
inline string repr(const T& value) {
	std::ostringstream oss;
	oss << ANSI_NUM << value << ANSI_RST;
	return oss.str();
}

// repr template specializations (not escaping value atm)
template <> inline string repr(const bool& value) { return string(ANSI_NUM) + (value ? "true" : "false"); }
template <> inline string repr(const string& value) { return ANSI_STR "\"" + value + "\"" ANSI_PUNCT "s" ANSI_RST; }
template <> inline string repr(const char* const& value) { return string(ANSI_STR "\"") + value + "\"" ANSI_STR; }
template <> inline string repr(const char& value) { return string(ANSI_CHR "'") + value + "'" ANSI_RST; }
template <typename T> inline string repr(const T* value) {
	if (value)
		return string(ANSI_KWRD "const" ANSI_PUNCT "&") + ::repr(*value);
	return ANSI_PARAM "NULL";
}
template <typename T> inline string repr(T* value) {
	if (value)
		return string(ANSI_PUNCT "&") + ::repr(*value);
	return ANSI_PARAM "NULL";
}
template <typename T> inline string repr(const T* value, unsigned int size) {
	std::ostringstream oss;
	oss << ANSI_PUNCT "{" ANSI_RST;
	for (unsigned int i = 0; i < size; ++i) {
		if (i != 0)
			oss << ANSI_PUNCT ", " ANSI_RST;
		oss << ::repr(value[i]);
	}
	oss << ANSI_PUNCT "}" ANSI_RST;
	return oss.str();
}

void repr_init();
void repr_done();
// </GENERATED>
