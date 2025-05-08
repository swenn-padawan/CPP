#pragma once

#include "AForm.hpp"

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
		void				signForm(AForm& form) const;
		void				executeForm(const AForm &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

