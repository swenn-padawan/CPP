#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();

    // Méthode qui crée un formulaire basé sur son nom et la cible donnée
    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    // Liste des formules gérées par l'Intern
    AForm* createShrubberyCreationForm(const std::string& target) const;
    AForm* createRobotomyRequestForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;
};
