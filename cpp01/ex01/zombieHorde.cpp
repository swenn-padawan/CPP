#include "Zombie.hpp"

static Zombie	*newZombie(std::string name)
{
	Zombie	*z;

	z = new Zombie;
	z->setName(name);
	z->announce();
	return (z);
}

Zombie	*zombieHorde( int N, std::string name )
{
	int		i;
	Zombie	*first;
	Zombie	*z;

	i = N;
	while (N--)
	{
		if (i == N)
			first = newZombie(name);
		else
			z = newZombie(name);
	}
	return (first);
}
