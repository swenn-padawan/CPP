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
		Fixed& operator = (const Fixed& fixed);
		int	getRawBits( void ) const ;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<( std::ostream& out, const Fixed& fixed );
