#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

#define FORM_GRADE_TOO_LOW_MSG "AForm Grade Too Low"
#define FORM_GRADE_TOO_HIGH_MSG "AForm Grade Too High"
#define ALREADY_SIGNED_MSG "AForm Already Signed"

class AForm{
	public:
		AForm();
		AForm(const std::string &name, int gradeSign, int gradeExec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &src);
		~AForm();

		const std::string &getName() const;
		bool	getIsSigned() const;
		int		getGradeRequiredToSign() const;
		int		getGradeRequiredToExec() const;
		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &executor) const;

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

		class IsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool				isSigned;
		const int			gradeRequiredToSign;
		const int			gradeRequiredToExec;
		virtual void		Action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

