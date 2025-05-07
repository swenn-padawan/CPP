#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		class OpenFileExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		void		printTree();
		std::string	_filename;
};
