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

		Fixed operator + (const Fixed& fixed) const;
		Fixed operator - (const Fixed& fixed) const;
		Fixed operator * (const Fixed& fixed) const;
		Fixed operator / (const Fixed& fixed) const;

		Fixed	& operator ++ (void);
		Fixed	& operator -- (void);
		Fixed	operator ++ (int);
		Fixed	operator -- (int);

		bool operator > (const Fixed& fixed) const;
		bool operator < (const Fixed& fixed) const;
		bool operator >= (const Fixed& fixed) const;
		bool operator <= (const Fixed& fixed) const;
		bool operator == (const Fixed& fixed) const;
		bool operator != (const Fixed& fixed) const;

		int						getRawBits( void ) const ;
		void					setRawBits(int const raw);
		float					toFloat( void ) const;
		int						toInt( void ) const;
		static Fixed&			min(Fixed& first, Fixed& second);
		static Fixed const &	min(const Fixed& first, const Fixed& second);
		static Fixed&			max(Fixed& first, Fixed& second);
		static Fixed const &	max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<( std::ostream& out, const Fixed& fixed );
