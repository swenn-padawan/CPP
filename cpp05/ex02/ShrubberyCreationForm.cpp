#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _filename("default target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string filename) : AForm("ShrubberyCreationForm", 145, 137), _filename(filename)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_filename = other._filename;
	return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}


void	ShrubberyCreationForm::Action() const{
	std::fstream outfile ((_filename + std::string("_shrubbery")).c_str());

	if (outfile){
		outfile << "       &&& &&  & &&\n";
		outfile<< "     && &\\/&\\|& ()|/ @, &&\n";
		outfile<< "     &\\/(/&/&||/& /_/)_&/_&\n";
		outfile<< "  &() &\\/&|()|/&\\/ '%\" & ()\n";
		outfile<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		outfile<< "&&   && & &| &| /& & % ()& /&&\n";
		outfile<< " ()&_---()&\\&\\|&&-&&--%---()~\n";
		outfile<< "     &&     \\|||\n";
		outfile<< "             |||\n";
		outfile<< "             |||\n";
		outfile<< "             |||\n";
		outfile<< "       , -=-~  .-^- _\n";
		outfile.close();
	}
	else 
		throw ShrubberyCreationForm::OpenFileExeption();
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}
