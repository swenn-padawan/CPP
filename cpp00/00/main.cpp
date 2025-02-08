#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string line;
	
	std::cout << "Please Enter The First Name:" << std::endl;
	std::getline (std::cin, line);
	while (line.empty())
	{
		if (line.empty()){
			std::cout << "Error!: < You Cannot Enter an Empty String >" << std::endl;
		}
		else if (std::cin.eof())
			std::cout << "Nice Try\n" << std::endl;
		else if (line == "ADD")
			Phonebook::Add(line);
		else if (line == "SEARCH")
			Phonebook::Search();
		else if(line == "EXIT")
			exit(1);
		std::getline (std::cin, line);
		std::cout << "Please Enter The First Name:" << std::endl;
	}
}
