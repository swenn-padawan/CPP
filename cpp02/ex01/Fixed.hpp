#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed& operator = (const Fixed &fixed);
		Fixed& operator << (const Fixed &fixed);
		int	getRawBits( void );
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};
