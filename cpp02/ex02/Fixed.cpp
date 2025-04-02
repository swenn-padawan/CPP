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
	std::cout << "Copy Constructor Called" << std::endl;
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

Fixed Fixed::operator + (const Fixed& fixed) const {
	Fixed	result;

	result.value = this->value + fixed.value;
	return (result);
}

Fixed Fixed::operator - (const Fixed& fixed) const {
	Fixed	result;

	result.value = this->value - fixed.value;
	return (result);
}

Fixed Fixed::operator * (const Fixed& fixed) const {
	Fixed	result;

	result.value = (this->value * fixed.value) >> bits;
	return (result);
}

Fixed Fixed::operator / (const Fixed& fixed) const {
	Fixed	result;

	result.value = (this->value << bits) / fixed.value;
	return (result);
}

bool Fixed::operator > (const Fixed& fixed) const{
	return (this->value > fixed.value);
}

bool Fixed::operator < (const Fixed& fixed) const{
	return (this->value < fixed.value);
}

bool Fixed::operator >= (const Fixed& fixed) const{
	return (this->value >= fixed.value);
}

bool Fixed::operator <= (const Fixed& fixed) const{
	return (this->value <= fixed.value);
}

bool Fixed::operator == (const Fixed& fixed) const{
	return (this->value == fixed.value);
}

bool Fixed::operator != (const Fixed& fixed) const{
	return (this->value != fixed.value);
}

Fixed& Fixed::operator -- ( void ){
	value--;
	return (*this);
}

Fixed& Fixed::operator ++ ( void ){
	value++;
	return (*this);
}

Fixed Fixed::operator -- ( int ){
	Fixed old(*this);
	value--;
	return (old);
}

Fixed Fixed::operator ++ ( int ){
	Fixed old(*this);
	value++;
	return (old);
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

Fixed	&Fixed::max(Fixed &first, Fixed &second){
	return (first > second ? first : second);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second){
	return (first < second ? first : second);
}

Fixed const	&Fixed::max(const Fixed &first, const Fixed &second){
	return (first > second ? first : second);
}

Fixed const &Fixed::min(const Fixed &first, const Fixed &second){
	return (first < second ? first : second);
}
