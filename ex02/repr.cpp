#include <iostream>

#include "repr.hpp"

void repr_init() {
	std::cout << ANSI_FG;
	// std::cout << "\x1b\x5b\x48\x1b\x5b\x32\x4a";
}

void repr_done() {
	std::cout << ANSI_RST_FR << "\n";
}
