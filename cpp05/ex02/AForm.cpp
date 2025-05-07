
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
	: _name("DefaultAForm"),
	isSigned(false),
	gradeRequiredToSign(50),
	gradeRequiredToExec(50),
	GradeTooLowException(GRADE_TOO_LOW_MSG),
	GradeTooHighException(GRADE_TOO_HIGH_MSG),
	AlreadySignedException(ALREADY_SIGNED_MSG)
{}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: _name(name),
	isSigned(false),
	gradeRequiredToSign(gradeSign),
	gradeRequiredToExec(gradeExec),
	GradeTooLowException(GRADE_TOO_LOW_MSG),
	GradeTooHighException(GRADE_TOO_HIGH_MSG),
	AlreadySignedException(ALREADY_SIGNED_MSG)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException;
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException;
}

AForm::AForm(const AForm &copy)
	: _name(copy._name),
	isSigned(copy.isSigned),
	gradeRequiredToSign(copy.gradeRequiredToSign),
	gradeRequiredToExec(copy.gradeRequiredToExec),
	GradeTooLowException(copy.GradeTooLowException),
	GradeTooHighException(copy.GradeTooHighException),
	AlreadySignedException(copy.AlreadySignedException)
{}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

// Destructeur
AForm::~AForm() {}

// Accesseurs
const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeRequiredToSign() const {
	return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExec() const {
	return gradeRequiredToExec;
}

// Méthode de signature
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException;
	if (this->isSigned)
		throw AlreadySignedException;
	isSigned = true;
}

// Surcharge opérateur <<
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", AForm (signed: " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign: " << form.getGradeRequiredToSign()
	   << ", grade to execute: " << form.getGradeRequiredToExec() << ")";
	return os;
}
