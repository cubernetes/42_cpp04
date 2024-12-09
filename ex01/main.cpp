#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using std::cout;

int main()
{
	cout << "CONSTRUCTING ANIMALS\n";
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	cout << '\n';

	cout << "ANIMAL TYPES\n";
	cout << animal->getType() << '\n';
	cout << cat->getType() << '\n';
	cout << dog->getType() << '\n';
	cout << '\n';

	cout << "ANIMAL SOUNDS\n";
	animal->makeSound();
	cat->makeSound(); // will output the cat sound!
	dog->makeSound();
	cout << '\n';

	cout << "DESTRUCTING ANIMALS\n";
	delete animal;
	delete dog;
	delete cat;
	cout << '\n';

	cout << "CONSTRUCTING WRONG ANIMALS\n";
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	cout << '\n';

	cout << "ANIMAL TYPES\n";
	cout << wronganimal->getType() << '\n';
	cout << wrongcat->getType() << '\n';
	cout << '\n';

	cout << "ANIMAL SOUNDS\n";
	wronganimal->makeSound();
	wrongcat->makeSound();
	cout << "WARNING. THE WRONG CAT IS NOT MAKING WRONG CAT NOISES. ERRRRRR\n";
	cout << '\n';

	cout << "DESTRUCTING WRONG ANIMALS\n";
	delete wronganimal;
	delete wrongcat;

	return 0;
}
