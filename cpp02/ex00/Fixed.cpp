#include "Fixed.hpp"

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &fixed){
	this->value = fixed.value;
}

Fixed::~Fixed( void ){
	std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator = ( Fixed const &fixed ){
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		value = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits function called" << std::endl;
	value  = raw;
}

