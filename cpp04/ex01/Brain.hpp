#pragma once
#include <iostream>

class Brain{
	public:
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &animal);
		std::string ideas[100];
};
