#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no name"), _grade(150), GradeTooHighException(GRADE_TOO_HIGH_MSG), GradeTooLowException(GRADE_TOO_LOW_MSG){}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name), GradeTooHighException(GRADE_TOO_HIGH_MSG), GradeTooLowException(GRADE_TOO_LOW_MSG){
	if (grade < 1)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException;
	_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name),
	  _grade(copy._grade),
	  GradeTooHighException(copy.GradeTooHighException),
	  GradeTooLowException(copy.GradeTooLowException) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
		this->GradeTooHighException = rhs.GradeTooHighException;
		this->GradeTooLowException = rhs.GradeTooLowException;
	}
	return *this;
}

int	Bureaucrat::getGrade() const {return _grade;}

const std::string Bureaucrat::getName() const {return _name;}

void Bureaucrat::setGrade(const int grade){
	if (grade < 1)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException;
	_grade = grade;
}

void	Bureaucrat::incrGrade(void){
	if (_grade - 1 < 1)
		throw GradeTooHighException;
	_grade--;
}

void	Bureaucrat::decrGrade(void){
	if (_grade + 1 > 150)
		throw GradeTooLowException;
	_grade++;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldn’t sign " << form.getName()
		          << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& man){
	std::cout << man.getName() << ", bureaucrat grade " << man.getGrade() << std::endl;
	return (os);
}

