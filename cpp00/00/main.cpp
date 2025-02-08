#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	std::string line;
	PhoneBook	Phonebook;	
	Phonebook.print_menu();
	std::cout << "Please Enter The First Name:" << std::endl;
	std::getline (std::cin, line);
	while (1)
	{
		if (line.empty()){
			std::cout << "Error!: < You Cannot Enter an Empty String >" << std::endl;
			continue ;
		}
		else if (std::cin.eof())
			std::cout << "Nice Try\n" << std::endl;
		else if (line == "ADD")
			Phonebook.Add(line);
		else if (line == "SEARCH")
			Phonebook.Search();
		else if(line == "EXIT")
			return (1);
		else
		 std::cout << "I don't know this word..." << std::endl;
	}
}
