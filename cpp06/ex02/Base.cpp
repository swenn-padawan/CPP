#include "Base.hpp"

Base::~Base(){}

Base	*generate(void){
	srand(time(NULL));
	int	value = rand() % 3;
	if (value == 0)
		return (new A);
	if (value == 1)
		return (new B);
	return (new C);
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		UNUSED(a)
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		UNUSED(b);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		UNUSED(c);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}
