#include <iostream>
#include <time.h>
#include <stdlib.h>

class Base{
	public:
		virtual ~Base();
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

/*- @brief: Randomly instantiates A, B or C -*/
Base *generate(void);

/*- @brief: Print the actual type of the object pointed by p (A, B or C)*/
void	identify(Base *p);

/*- @brief: Print the actual type of the object reference */
void	identify(Base& p);

#define UNUSED(x) ((void)x);
