#include <iostream>

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "repr.hpp"

using std::cout;

int main() {
	repr_init();
	{
		cout << "\x1b\x5b""41;30mSubject main" ANSI_RST "\n";

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		
		Ice *ice = dynamic_cast<Ice*>(me->give(0));
		Cure *cure = dynamic_cast<Cure*>(me->give(1));
		delete ice;
		delete cure;

		delete bob;
		delete me;
		delete src;
	}
	{
		cout << "\x1b\x5b""41;30mMy tests" ANSI_RST "\n";

		cout << "\x1b\x5b""31m""Constructing Ice" ANSI_RST "\n";
		Ice i;
		cout << "\x1b\x5b""31m""Constructing Character bob" ANSI_RST "\n";
		Character bob("bob");

		cout << "\x1b\x5b""31m""Borrowing ice" ANSI_RST "\n";
		bob.borrow(&i);
		cout << "\x1b\x5b""31m""Equiping cure" ANSI_RST "\n";
		bob.equip(new Cure());

		cout << "\x1b\x5b""31m""This is bob" ANSI_RST "\n";
		cout << bob << '\n';

		cout << "\x1b\x5b""31m""Trying to unequip item that bob owns" ANSI_RST "\n";
		bob.unequip(1);

		cout << "\x1b\x5b""31m""Transferring ownership of Cure from bob to outside pointer" ANSI_RST "\n";
		Cure* i2 = dynamic_cast<Cure*>(bob.give(1));

		cout << "\x1b\x5b""31m""This is bob now" ANSI_RST "\n";
		cout << bob << '\n';

		cout << "\x1b\x5b""31m""Deleting cure" ANSI_RST "\n";
		delete i2;

		cout << "\x1b\x5b""31m""Trying to transfer ownership of borrowed item" ANSI_RST "\n";
		bob.give(0);

		cout << "\x1b\x5b""31m""Unequiping Ice" ANSI_RST "\n";
		bob.unequip(0);

		cout << "\x1b\x5b""31m""This is bob now" ANSI_RST "\n";
		cout << bob << '\n';

		cout << "\x1b\x5b""31m""Leaving scope" ANSI_RST "\n";
	}
	repr_done();
	return 0;
}
