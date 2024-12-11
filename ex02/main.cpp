#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using std::cout;

void foo(const AAnimal& arg) {
	cout << "\n\033[31mCalling virtual function from inside foo() (arg passed as const AAnimal REFERENCE)\n\x1b\x5bm" ANSI_RST;
	arg.makeSound();
	// arg CAN'T be downcasted to a Dog!
}

void bar(Dog arg) {
	cout << "\n\033[31mCalling virtual function from inside bar (arg passed as Dog)\n\x1b\x5bm" ANSI_RST;
	arg.makeSound();
}

int main()
{
	repr_init();
{
	cout << "\n\033[30;41mEntering scope 1 -- MY selection of tests" ANSI_RST "\n";

	cout << "\n\033[31mConstructing default DOG" ANSI_RST "\n";
	const AAnimal* dog = new Dog();

	cout << "\n\033[31mConstructing WOOFY" ANSI_RST "\n";
	AAnimal* woofy = new Dog("Woofy");

	cout << "\n\033[31mConstructing default CAT" ANSI_RST "\n";
	AAnimal* cat = new Cat();

	cout << "\n\033[31mConstructing KITTY" ANSI_RST "\n";
	Cat kitty("Kitty");

	cout << "\n\033[31mDeleting DOG" ANSI_RST "\n";
	delete dog; //should not create a leak

	cout << "\n\033[31mCopy-Assigning (DEEPCOPY) from CAT to KITTY (variable called kitty will now point to a deepcopy CAT, and the old KITTY will be GONE)" ANSI_RST "\n";
	kitty = *dynamic_cast<Cat*>(cat); // *cat is an animal, but it's polymorphic, so dynamic downcast to Cat is well-defined

	cout << "\n\033[31mDeleting CAT" ANSI_RST "\n";
	delete cat;

	cout << "\n\033[31mPrinting copied CAT to prove DEEPCOPY" ANSI_RST "\n";
	cout << kitty << '\n';

	cout << "\n\033[31mCalling virtual function from outside" ANSI_RST "\n";
	woofy->makeSound();

	cout << "\n\033[31mPassing WOOFY to foo(AAnimal) (by value!)" ANSI_RST "\n";
	foo(*woofy);

	cout << "\n\033[31mPassing WOOFY too bar(Dog) (by value!) (many copy constructor calls -> expensive)" ANSI_RST "\n";
	bar(*dynamic_cast<Dog*>(woofy));

	cout << "\n\033[31mDeleting WOOFY" ANSI_RST "\n";
	delete woofy;

	cout << "\n\033[31mLeaving scope 1" ANSI_RST "\n";
}
{
	cout << "\n\033[30;41mEntering scope 2 -- Tests required by project" ANSI_RST "\n";
	static const unsigned int n_animals = 4;

	cout << "\n\033[31mInitializing array[4] of Animals*" ANSI_RST "\n";
	AAnimal *animals[n_animals] = {new Cat(), new Dog(), new Cat(), new Dog()};

	cout << "\n\033[31mDeleting animals" ANSI_RST "\n";
	for (unsigned int i = 0; i < n_animals; ++i)
		delete animals[i];

	cout << "\n\033[31mLeaving scope 2" ANSI_RST "\n";
}
	repr_done();
	return 0;
}
