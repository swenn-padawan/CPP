
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat boss("Alice", 1); // Grade élevé => peut tout faire
		ShrubberyCreationForm form("home");

		std::cout << "Signing the form...\n";
		boss.signForm(form); // ou form.beSigned(boss);

		std::cout << "Executing the form...\n";
		boss.executeForm(form); // ou form.execute(boss);

		//std::cout << "Success: File 'home_shrubbery' should be created.\n";
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
