#include "Contact.hpp"

std::string	Contact::getFirstName(void) const
{
	return this->firstName;
}

std::string	Contact::getLastName(void) const
{
	return this->lastName;
}

std::string	Contact::getNickname(void) const
{
	return this->nickname;
}

std::string	Contact::getNumber(void) const
{
	return this->number;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->darkestSecret;
}

void	Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}

void	Contact::setNumber(const std::string &number)
{
	this->number = number;
}

void	Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
