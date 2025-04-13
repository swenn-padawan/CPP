#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		~WrongCat();
		WrongCat &operator=(const WrongCat &cat);
		void		setType(const std::string _type);
		std::string	getType( void );

		void	makeSound( void ) const;
};
