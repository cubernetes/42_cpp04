#pragma once
#include <string>

#include "AMateria.hpp"

using std::string;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(const string& type) = 0;
};
