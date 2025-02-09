#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook{
	private:
		Contact			contacts[8];
		int				currentIndex;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	Add();
		void	Search();
	void	print_menu();
};

#endif
