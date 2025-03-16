#include "Zombie.hpp"

int	main( void )
{
	Zombie	*z;
	
	z = zombieHorde(10, "oui");
	delete [](z);
	return (0);
}
