#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed& operator = (const Fixed &fixed);
		int	getRawBits( void );
		void setRawBits(int const raw);
};
