#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string darkestSecret;
		std::string currentIndex;
	public:
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getNumber() const;
		std::string	getDarkestSecret() const;
		void	setFirstName(const std::string &firstName);
		void	setLastName(const std::string &lastName);
		void	setNickname(const std::string &nickName);
		void	setNumber(const std::string &number);
		void	setDarkestSecret(const std::string &darkestSecret);
};

#endif
