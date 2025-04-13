#include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &cat);
		void		setType(const std::string _type);
		std::string	getType( void );

		void	makeSound( void ) const;
};
