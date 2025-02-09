#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void	PhoneBook::print_menu()
{
	std::cout << "╔══════════════════════════════════╗" << std::endl;
	std::cout << "║ Welcome to PhoneBook             ║" << std::endl;
	std::cout << "╚══════════════════════════════════╝" << std::endl;
	std::cout << "╔══════════════════════════════════╗" << std::endl;
	std::cout << "║ Here you can:                    ║" << std::endl;
	std::cout << "║                                  ║" << std::endl;
	std::cout << "║ ADD a Contact                    ║" << std::endl;
	std::cout << "║ SEARCH for a Contact             ║" << std::endl;
	std::cout << "║ EXIT                             ║" << std::endl;
	std::cout << "╚══════════════════════════════════╝" << std::endl;
}

PhoneBook::~PhoneBook(void) {}

PhoneBook::PhoneBook(void)  {
	currentIndex = 0;
}

void	PhoneBook::Add() {
	std::string	str;

	std::cout << "Enter the FirstName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "You can't put empty input !" << std::endl;
		std::cout << "Enter the FirstName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setFirstName(str);
	std::cout << "Enter the LastName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "You can't put empty input !" << std::endl;
		std::cout << "Enter the LastName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setLastName(str);
	std::cout << "Enter the NickName:" << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "You can't put empty input !" << std::endl;
		std::cout << "Enter the NickName:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setNickname(str);
	std::cout << "Enter the Number: " << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "You can't put empty input !" << std::endl;
		std::cout << "Enter the Number:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setNumber(str);
	std::cout << "Enter the Secret: " << std::endl;
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "You can't put empty input !" << std::endl;
		std::cout << "Enter the Secret:" << std::endl;
		std::getline(std::cin, str);
	}
	contacts[currentIndex].setDarkestSecret(str);
	currentIndex = (currentIndex + 1) % 8;
}

std::string formatField(std::string str) {
    if (str.length() > 9) {
        return str.substr(0, 9) + ".";
    }
	while (str.length() < 10){
		str = str + " ";
	}
    return (str);
}

void	PhoneBook::Search(void)
{
	std::string	str;
	int			nb;

	for (int i = 0; i < this->currentIndex; i++) {
        std::cout << "|" << i + 1 << "         "
				  << "|" << formatField(contacts[i].getFirstName())
                  << "|" << formatField(contacts[i].getLastName())
                  << "|" << formatField(contacts[i].getNickname()) << "|" << std::endl;
    }
	while (1)
	{
		std::cout << "Which Contact interest you ?" << std::endl;
		std::getline(std::cin, str);
		nb = std::atoi(str.c_str());
		if (nb < 1 || nb > 9)
		{
			std::cout << "The number is out of range !" << std::endl;
			continue ;
		}
		nb--;
		std::cout << "Here's the informations of " << contacts[nb].getNickname() << std::endl;
		std::cout << contacts[nb].getFirstName() << std::endl <<
			contacts[nb].getLastName() << std::endl << 
			contacts[nb].getNickname() << std::endl <<
			contacts[nb].getNumber() << std::endl <<
			contacts[nb].getDarkestSecret() << std::endl;
		break ;
	}
}
