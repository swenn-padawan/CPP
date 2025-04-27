#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
//	Animal	animal;

	Dog *dog = new Dog;
	Dog	*tmp = new Dog(*dog);

	dog->makeSound();
	tmp->makeSound();

	delete dog;
	delete tmp;

	std::cout << "FOR THE CAT" << std::endl;

	Cat *cat = new Cat;
	Cat	*tmp_cat = new Cat(*cat);
	
	cat->makeSound();
	tmp_cat->makeSound();


	delete cat;
	delete tmp_cat;
}
