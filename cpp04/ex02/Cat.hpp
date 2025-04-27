#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &cat);
		void		setType(const std::string _type);
		std::string	getType( void );

		Brain	*getBrain(void);
		void	makeSound( void ) const;

	private:
		Brain* brain;
};
