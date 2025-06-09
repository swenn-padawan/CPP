#include "RPN.hpp"
#include <iostream>


int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
		return 1;
	}
	try {
		rpn(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl; 
	}
}
