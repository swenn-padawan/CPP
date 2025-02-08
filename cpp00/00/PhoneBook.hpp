#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>

class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	Add(std::string line);
	private:
		Contact			contacts[8];
		int				currentIndex;
};

#endif
