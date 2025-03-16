#include <iostream>

int	main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string address = " << &string << "\n";
	std::cout << "stringPTR holds = " << stringPTR << "\n";
	std::cout << "stringREF holds = " << &stringREF << "\n\n";

	std::cout << "string value = " << string << "\n";
	std::cout << "the value pointed by stringPTR = " << stringPTR << "\n";
	std::cout << "the memory hold by string REF = " << stringREF << "\n";

}
