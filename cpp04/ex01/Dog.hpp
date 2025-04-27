#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &dog);
		void		setType(const std::string _type);
		std::string	getType( void );

		void	makeSound( void ) const;
		Brain	*getBrains(void);	

	private:
		Brain* brain;
};
