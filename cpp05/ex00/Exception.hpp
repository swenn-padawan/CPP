#pragma once

#include <iostream>

#define GRADE_TOO_LOW_MSG "Grade Too Low"
#define GRADE_TOO_HIGH_MSG "Grade Too High"

class	GradeException: public std::exception{
	public:
		GradeException(const std::string &msg);
		virtual ~GradeException() throw();
		virtual const char* what() const throw();
	private:
		std::string _message;
};
