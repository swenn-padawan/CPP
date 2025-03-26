#include "Zombie.hpp"

#define NB_ZOMBIES 10

int	main( void )
{
	Zombie	*z;
	
	z = zombieHorde(NB_ZOMBIES, "Jack");
	for (int i = 0; i < NB_ZOMBIES; i++)
		z[i].announce();

	delete [] z;
	return (0);
}
