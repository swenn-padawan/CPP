#include "Zombie.hpp"

int	main( void )
{
	Zombie	*z;
	
	z = newZombie("wallas");
	randomChump("gilbert");
	delete (z);
	return (0);
}
