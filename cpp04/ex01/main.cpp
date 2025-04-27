#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog *dog = new Dog;

	std::cout << "addresse de dog::brain = " << " " << dog->getBrains() << std::endl;

	Dog	*tmp = new Dog(*dog);
	
	std::cout << "addresse de dog::brain = " << " " << tmp->getBrains() << std::endl;

	delete dog;
	delete tmp;

	std::cout << "FOR THE CAT" << std::endl;
	Cat *cat = new Cat;

	std::cout << "addresse de dog::brain = " << " " << cat->getBrain() << std::endl;

	Cat	*tmp_cat = new Cat(*cat);
	
	std::cout << "addresse de dog::brain = " << " " << tmp_cat->getBrain() << std::endl;

	delete cat;
	delete tmp_cat;
}
