#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

void	print_menu()
{
	std::cout << "╔══════════════════════════════════╗" << std::endl;
	std::cout << "║		  Welcome to PhoneBook       ║" << std::endl;
	std::cout << "╚══════════════════════════════════╝" << std::endl;
	std::cout << "╔══════════════════════════════════╗" << std::endl;
	std::cout << "║	Here you can:					 ║" << std::endl;
	std::cout << "║                                  ║" << std::endl;
	std::cout << "║ ADD a Contact					 ║" << std::endl;
	std::cout << "║ SEARCH for a Contact		     ║" << std::endl;
	std::cout << "║ EXIT						     ║" << std::endl;
	std::cout << "╚══════════════════════════════════╝" << std::endl;
}

PhoneBook::~PhoneBook(void) {}

PhoneBook::PhoneBook(void)  {
	currentIndex = 0;
}

void	PhoneBook::Add(std::string line) {
	std::string	str;

	std::cout << "Enter the FirstName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the FirstName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setFirstName(line);
	std::cout << "Enter the LastName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the LastName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setLastName(line);
	std::cout << "Enter the NickName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the LastName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setFirstName(line);
	currentIndex = (currentIndex + 1) % 8;
}
