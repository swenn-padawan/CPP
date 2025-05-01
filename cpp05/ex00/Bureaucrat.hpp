#pragma once

#include <iostream>
#include "Exception.hpp"

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		int					getGrade(void) const;
		void				setGrade(const int grade);
		const std::string	getName(void) const;
		void				incrGrade(void);
		void				decrGrade(void);

	private:
		const std::string	_name;
		int					_grade;
		GradeException		GradeTooHighException;
		GradeException		GradeTooLowException;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

