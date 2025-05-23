#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>

// Couleurs ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

void separator(const std::string& title) {
	std::cout << CYAN << "\n======= " << title << " =======\n" << RESET;
}

bool checkFileCreatedAndFilled(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) return false;

	std::string line;
	bool hasContent = false;
	while (std::getline(file, line)) {
		if (!line.empty()) {
			hasContent = true;
			break;
		}
	}
	file.close();
	return hasContent;
}

int main() {
	std::srand(std::time(NULL)); // pour Robotomy

	try {
		Bureaucrat low("Low", 150);
		Bureaucrat mid("Mid", 70);
		Bureaucrat high("High", 1);

		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Wall-E");
		PresidentialPardonForm pardon("Ford Prefect");

		separator("1. Tentative de signature avec grade trop bas");
		try {
			low.signForm(shrub); // échoue
			std::cout << RED << "[FAIL] Low a signé avec grade insuffisant" << RESET << std::endl;
		} catch (...) {
			std::cout << GREEN << "[OK] Signature refusée comme prévu" << RESET << std::endl;
		}

		separator("2. Signature et exécution avec grade suffisant");
		try {
			high.signForm(shrub);
			high.executeForm(shrub);
			if (checkFileCreatedAndFilled("Home_shrubbery"))
				std::cout << GREEN << "[OK] Fichier créé et contenu écrit" << RESET << std::endl;
			else
				std::cout << RED << "[FAIL] Fichier non créé ou vide" << RESET << std::endl;
		} catch (std::exception& e) {
			std::cout << RED << "[FAIL] Exception : " << e.what() << RESET << std::endl;
		}

		separator("3. Exécution sans signature");
		try {
			mid.executeForm(robot); // échoue
			std::cout << RED << "[FAIL] Formulaire exécuté sans signature" << RESET << std::endl;
		} catch (...) {
			std::cout << GREEN << "[OK] Exécution refusée comme prévu" << RESET << std::endl;
		}

		separator("4. Signature mais exécution avec grade insuffisant");
		try {
			mid.signForm(robot);
			mid.executeForm(robot); // échoue
			std::cout << RED << "[FAIL] Exécuté avec un grade insuffisant" << RESET << std::endl;
		} catch (...) {
			std::cout << GREEN << "[OK] Refusé comme prévu" << RESET << std::endl;
		}

		separator("5. Robotomy avec High (5 essais, 50% expected)");
		high.executeForm(robot);
		for (int i = 0; i < 5; ++i) {
			std::cout << YELLOW << "Tentative " << (i + 1) << ": " << RESET;
			high.executeForm(robot);
			// on ne peut pas détecter automatiquement succès/échec ici, à moins d’intercepter std::cout
		}
		std::cout << GREEN << "[OK] Robotomy exécutée plusieurs fois" << RESET << std::endl;

		separator("6. Pardon présidentiel");
		try {
			high.signForm(pardon);
			high.executeForm(pardon);
			std::cout << GREEN << "[OK] Pardon exécuté correctement" << RESET << std::endl;
		} catch (...) {
			std::cout << RED << "[FAIL] Problème dans le pardon" << RESET << std::endl;
		}

	} catch (std::exception& e) {
		std::cerr << RED << "Exception dans main : " << e.what() << RESET << std::endl;
	}
	return 0;
}
