
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::Action() const {
	std::cout << "Brrrrrrrzzzzt... *drilling noises*" << std::endl;

	std::srand(std::time(NULL));  // initialize RNG
	if (std::rand() % 2)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}
