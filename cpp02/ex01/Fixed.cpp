#include "Fixed.hpp"

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed( const int value ){
	std::cout << "Int constructor called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed( const float value ){
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &fixed){
	*this = fixed;
}

Fixed::~Fixed( void ){
	std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &fixed ){
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.value;
	return (*this);
}

std::ostream& operator<<( std::ostream& out, const Fixed &fixed ){
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits function called" << std::endl;
	value  = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->value / (1 << bits));
}

int	Fixed::toInt( void ) const {
	return (this->value >> bits);
}
