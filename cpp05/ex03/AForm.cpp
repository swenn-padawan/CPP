
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
	: _name("DefaultAForm"),
	isSigned(false),
	gradeRequiredToSign(50),
	gradeRequiredToExec(50)
{}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: _name(name),
	isSigned(false),
	gradeRequiredToSign(gradeSign),
	gradeRequiredToExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
	: _name(copy._name),
	isSigned(copy.isSigned),
	gradeRequiredToSign(copy.gradeRequiredToSign),
	gradeRequiredToExec(copy.gradeRequiredToExec)
{}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

AForm::~AForm() {}

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

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (isSigned == false)
		throw IsNotSignedException();
	if (gradeRequiredToExec < executor.getGrade())
		throw GradeTooLowException();
	Action();	
	
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", AForm (signed: " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign: " << form.getGradeRequiredToSign()
	   << ", grade to execute: " << form.getGradeRequiredToExec() << ")";
	return os;
}
