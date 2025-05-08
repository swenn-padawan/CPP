#pragma once

#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

	virtual void Action() const;
};
