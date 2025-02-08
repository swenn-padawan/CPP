#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

void	PhoneBook::print_menu()
{
	std::cout << "╔══════════════════════════════════╗" << std::endl;
	std::cout << "║		  Welcome to PhoneBook          ║" << std::endl;
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
	while (str == "\n")
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the FirstName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setFirstName(line);
	std::cout << "Enter the LastName:" << std::endl;
	std::getline(std::cin, str);
	while (str == "\n")
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the LastName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setLastName(line);
	std::cout << "Enter the NickName:" << std::endl;
	std::getline(std::cin, str);
	while (str == "\n")
	{
		std::cout << "Empty is not a Name !!!" << std::endl;
		std::cout << "Enter the NickName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setNickname(line);
	std::cout << "Enter the Number: " << std::endl;
	std::getline(std::cin, str);
	while (str == "\n")
	{
		std::cout << "Empty is not a Number !!!" << std::endl;
		std::cout << "Enter the Number:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setNumber(line);
	std::cout << "Enter the Secret: " << std::endl;
	std::getline(std::cin, str);
	while (str == "\n")
	{
		std::cout << "Empty is not a Secret !!!" << std::endl;
		std::cout << "Enter the Secret:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setDarkestSecret(line);
	currentIndex = (currentIndex + 1) % 8;
}

void	PhoneBook::Search(void)
{
#ifdef BONUS
	std::cout << "╔══════╦══════════════╦══════════════╦══════════════╗" << std::endl;
    std::cout << "║  📌  ║ FirstName    ║ Name		   ║ Nickname     ║" << std::endl;
    std::cout << "╠══════╬══════════════╬══════════════╬══════════════╣" << std::endl;

    for (int i = 0; i < currentIndex; i++) {
        std::cout << " ║ " << this->currentIndex
                  << " ║ " << contacts[i].getFirstName().substr(0, 9) + "."
                  << " ║ " << contacts[i].getLastName().substr(0, 9) + "."
                  << " ║ " << contacts[i].getNickname().substr(0, 9) << " ║" << std::endl;
    }

    std::cout << "╚══════╩══════════════╩══════════════╩══════════════╝" << std::endl;
#endif // BONUS
}
