#pragma once

#include "Exception.hpp"

class Bureaucrat;

#define FORM_GRADE_TOO_LOW_MSG "Form Grade Too Low"
#define FORM_GRADE_TOO_HIGH_MSG "Form Grade Too High"
#define ALREADY_SIGNED_MSG "Form Already Signed"

class Form{
	public:
		Form();
		Form(const std::string &name, int gradeSign, int gradeExec);
		Form(const Form &copy);
		Form &operator=(const Form &src);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExec() const;
		void	beSigned(const Bureaucrat &bureaucrat);


	private:
		const std::string	_name;
		bool				isSigned;
		const int			gradeRequiredToSign;
		const int			gradeRequiredToExec;
		GradeException		GradeTooLowException;
		GradeException		GradeTooHighException;
		GradeException		AlreadySignedException;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

