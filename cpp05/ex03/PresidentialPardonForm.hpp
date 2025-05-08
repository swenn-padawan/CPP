#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	virtual void Action() const;
};
