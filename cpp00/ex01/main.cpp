#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	std::string line;
	PhoneBook	Phonebook;	
	while (1)
	{
		Phonebook.print_menu();
		std::getline (std::cin, line);
		if (line.empty()){
			std::cout << "Error!: < You Cannot Enter an Empty String >" << std::endl;
			continue ;
		}
		else if (line == "ADD")
			Phonebook.Add();
		else if (line == "SEARCH")
			Phonebook.Search();
		else if(line == "EXIT")
			return (1);
		else
		 std::cout << "I don't know this word..." << std::endl;
	}
}
