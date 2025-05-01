
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructeur par défaut
Form::Form()
	: _name("DefaultForm"),
	isSigned(false),
	gradeRequiredToSign(50),
	gradeRequiredToExec(50),
	GradeTooLowException(GRADE_TOO_LOW_MSG),
	GradeTooHighException(GRADE_TOO_HIGH_MSG),
	AlreadySignedException(ALREADY_SIGNED_MSG)
{}

Form::Form(const std::string &name, int gradeSign, int gradeExec)
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

// Constructeur par copie
Form::Form(const Form &copy)
	: _name(copy._name),
	isSigned(copy.isSigned),
	gradeRequiredToSign(copy.gradeRequiredToSign),
	gradeRequiredToExec(copy.gradeRequiredToExec),
	GradeTooLowException(copy.GradeTooLowException),
	GradeTooHighException(copy.GradeTooHighException),
	AlreadySignedException(copy.AlreadySignedException)
{}

// Surcharge d'opérateur d'affectation
Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->isSigned = src.isSigned;
		// Les champs const ne peuvent pas être copiés
	}
	return *this;
}

// Destructeur
Form::~Form() {}

// Accesseurs
const std::string &Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeRequiredToSign() const {
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExec() const {
	return gradeRequiredToExec;
}

// Méthode de signature
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException;
	if (this->isSigned)
		throw AlreadySignedException;
	isSigned = true;
}

// Surcharge opérateur <<
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", Form (signed: " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign: " << form.getGradeRequiredToSign()
	   << ", grade to execute: " << form.getGradeRequiredToExec() << ")";
	return os;
}
