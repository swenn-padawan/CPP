#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    std::cout << BOLD << BLUE << "\n=== Test 1: Bureaucrat valide ===" << RESET << std::endl;
    try {
        Bureaucrat bureaucrat1("John", 50);
        std::cout << GREEN << bureaucrat1 << RESET << std::endl;
    }
    catch (const GradeException& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << BLUE << "\n=== Test 2: Grade trop élevé (Alice) ===" << RESET << std::endl;
    try {
        Bureaucrat Alice("Alice", 0); // Devrait lever une exception
    }
    catch (const GradeException& e) {
        std::cout << RED << "Alice: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << BLUE << "\n=== Test 3: Grade trop bas (Bob) ===" << RESET << std::endl;
    try {
        Bureaucrat bureaucrat3("Bob", 151); // Devrait lever une exception
    }
    catch (const GradeException& e) {
        std::cout << RED << "Bob: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << BLUE << "\n=== Test 4: Incrémentation / Décrémentation (Eve) ===" << RESET << std::endl;
    try {
        Bureaucrat bureaucrat4("Eve", 75);
        std::cout << GREEN << bureaucrat4 << RESET << std::endl;

        bureaucrat4.incrGrade(); // devient 74
        std::cout << CYAN << "Après incrément : " << bureaucrat4 << RESET << std::endl;

        bureaucrat4.decrGrade(); // redevient 75
        std::cout << CYAN << "Après décrément : " << bureaucrat4 << RESET << std::endl;
    }
    catch (const GradeException& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << BLUE << "\n=== Test 5: Limite basse (grade 150) ===" << RESET << std::endl;
    try {
        Bureaucrat bureaucrat5("Eve", 150);
        std::cout << GREEN << bureaucrat5 << RESET << std::endl;

        bureaucrat5.incrGrade(); // devient 149
        std::cout << CYAN << "Après incrément : " << bureaucrat5 << RESET << std::endl;

        bureaucrat5.decrGrade(); // redevient 150
        std::cout << CYAN << "Après décrément : " << bureaucrat5 << RESET << std::endl;
    }
    catch (const GradeException& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << BLUE << "\n=== Test 6: Limite haute (grade 1) ===" << RESET << std::endl;
    try {
        Bureaucrat bureaucrat5("Eve", 1);
        std::cout << GREEN << bureaucrat5 << RESET << std::endl;

        bureaucrat5.incrGrade(); // erreur
        std::cout << CYAN << "Après incrément : " << bureaucrat5 << RESET << std::endl;

        bureaucrat5.decrGrade(); // 2
        std::cout << CYAN << "Après décrément : " << bureaucrat5 << RESET << std::endl;
    }
    catch (const GradeException& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
