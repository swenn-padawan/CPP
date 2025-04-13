#include "Brain.hpp"

Brain::Brain( void ){
	std::cout << "Default constructor Called (BRAINS)" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Ceci est une idee\n";
}

Brain::~Brain( void ){}

Brain::Brain( const Brain &brain ){
	std::cout << "Copy constructor called (BRAINS)" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain &brain){
	if (this != &brain){
		for (int i = 0; i < 100; i++)
			ideas[i] = brain.ideas[i];
	}
	return (*this);
}
