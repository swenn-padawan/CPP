#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <iomanip>
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
	nbContact = 0;
}

std::string	getValidInput(const	std::string& prompt)
{
	std::string	input;

	while (1)
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, input) || std::cin.eof()){
			std::cout << "BYE BYE" << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (!input.empty())
			return (input);
		std::cout << "Please enter something" << std::endl;
	}
}

void	PhoneBook::Add() {
	std::string firstName = getValidInput("Enter the FirstName:");
	if (firstName.empty()) return ;
	contacts[currentIndex].setFirstName(firstName);

	std::string	lastName = getValidInput("Enter the LastName:");
	if (lastName.empty()) return ;
	contacts[currentIndex].setLastName(lastName);

	std::string	nickName = getValidInput("Enter the NickName:");
	if (nickName.empty()) return ;
	contacts[currentIndex].setNickname(nickName);

	std::string	number = getValidInput("Enter the Phone Number:");
	if (number.empty()) return ;
	contacts[currentIndex].setNumber(number);

	std::string	secret = getValidInput("Enter his Darkest Secret:");
	if (secret.empty()) return ;
	contacts[currentIndex].setDarkestSecret(secret);

	currentIndex = (currentIndex + 1) % 8;
	if (nbContact != 8)
		nbContact++;
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
	std::string str;
    int nb;

	if (nbContact == 0){
		std::cout << "No contacts are available, try to ADD some before SEARCH" << std::endl;
		return ;
	}
    std::cout << "╔═══════╦════════════╦════════════╦════════════╗" << std::endl;
    std::cout << "║   No  ║ First Name ║ Last Name  ║ Nickname   ║" << std::endl;
    std::cout << "╠═══════╬════════════╬════════════╬════════════╣" << std::endl;

    for (int i = 0; i < nbContact; i++) {
        std::cout << "║ " << std::setw(3) << i + 1 << "   ║ "  // Numéro de contact avec alignement
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << " ║ "
                  << std::setw(10) << formatField(contacts[i].getLastName()) << " ║ "
                  << std::setw(10) << formatField(contacts[i].getNickname()) << " ║" << std::endl;
    }
    std::cout << "╚═══════╩════════════╩════════════╩════════════╝" << std::endl;
	while (1)
	{
		std::cout << "Which Contact interest you ?" << std::endl;
		if (!std::getline(std::cin, str) || std::cin.eof()){
			std::cout << "BYE BYE" << std::endl;
			exit(1);
		}
		nb = std::atoi(str.c_str());
		if (nb < 1 || nb >= 9 || nb > nbContact)
		{
			std::cout << "The number is out of range !" << std::endl;
			continue ;
		}
		break ;
	}
	nb--;
	std::cout << "╔═══════╦════════════╦════════════╦════════════╦════════════╦════════════╗" << std::endl;
	std::cout << "║   No  ║ First Name ║ Last Name  ║  Nickname  ║   Number   ║   Secret   ║" << std::endl;
	std::cout << "╠═══════╬════════════╬════════════╬════════════╬════════════╬════════════╣" << std::endl;
    std::cout << "║ " << std::setw(3) << nb + 1 << "   ║ "
                  << std::setw(10) << formatField(contacts[nb].getFirstName()) << " ║ "
                  << std::setw(10) << formatField(contacts[nb].getLastName()) << " ║ "
                  << std::setw(10) << formatField(contacts[nb].getNickname()) << " ║ "
                  << std::setw(10) << formatField(contacts[nb].getNumber()) << " ║ "
                  << std::setw(10) << formatField(contacts[nb].getDarkestSecret()) << " ║" << std::endl;
    std::cout << "╚═══════╩════════════╩════════════╩════════════╩════════════╩════════════╝" << std::endl;
}
