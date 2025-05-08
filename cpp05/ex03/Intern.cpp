#include "Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    if (formName == "shrubbery creation") {
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return createShrubberyCreationForm(target);
    }
    else if (formName == "robotomy request") {
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return createRobotomyRequestForm(target);
    }
    else if (formName == "presidential pardon") {
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return createPresidentialPardonForm(target);
    }
    else {
        std::cout << "Intern: Form not recognized!" << std::endl;
        return nullptr;
    }
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}
