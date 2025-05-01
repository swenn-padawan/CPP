#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

void separator(const std::string &title) {
	std::cout << BLUE << "\n===== " << title << " =====" << RESET << std::endl;
}

int main() {
	// TEST 1: Bureaucrat valide
	separator("TEST 1 - Bureaucrat avec grade valide");
	Bureaucrat b1("Alice", 75);
	std::cout << b1 << std::endl;

	// TEST 2: Bureaucrat trop haut
	separator("TEST 2 - Bureaucrat avec grade 0");
	try {
		Bureaucrat b2("Bob", 0);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 3: Bureaucrat trop bas
	separator("TEST 3 - Bureaucrat avec grade 151");
	try {
		Bureaucrat b3("Charlie", 151);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 4: Form valide
	separator("TEST 4 - Création d'un Form valide");
	Form f1("FormA", 100, 50);
	std::cout << f1 << std::endl;

	// TEST 5: Form avec grade de signature trop haut
	separator("TEST 5 - Form avec grade de signature trop haut (0)");
	try {
		Form f2("FormB", 0, 50);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 6: Form avec grade d'exécution trop bas
	separator("TEST 6 - Form avec grade d'exécution trop bas (151)");
	try {
		Form f3("FormC", 100, 151);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 7: Signature réussie
	separator("TEST 7 - Signature réussie");
	Bureaucrat signer("Diane", 42);
	Form f4("FormD", 50, 100);
	signer.signForm(f4);
	std::cout << f4 << std::endl;

	// TEST 8: Signature échouée
	separator("TEST 8 - Signature échouée par grade trop bas");
	Bureaucrat low("Eve", 120);
	Form f5("FormE", 100, 50);
	low.signForm(f5);
	std::cout << f5 << std::endl;

	// TEST 9: Form déjà signé
	separator("TEST 9 - Signature d'un formulaire déjà signé");
	Bureaucrat signer2("Frank", 50);
	Form f6("FormF", 100, 50);
	signer2.signForm(f6); // 1ère signature
	signer2.signForm(f6); // 2e tentative
	std::cout << f6 << std::endl;

	// TEST 10: Incrémentation et décrémentation des grades aux limites
	separator("TEST 10 - Incrément/Decrément à la limite");
	try {
		Bureaucrat top("Grace", 1);
		std::cout << top << std::endl;
		top.incrGrade(); // Devrait échouer
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception (incr): " << e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat bot("Heidi", 150);
		std::cout << bot << std::endl;
		bot.decrGrade(); // Devrait échouer
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception (decr): " << e.what() << RESET << std::endl;
	}

	return 0;
}
