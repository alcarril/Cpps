

#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& objFixed) : fixedNum(objFixed.fixedNum) {
	std::cout << "Copy constructor called\n";
}

//pasa de int a fixed format
Fixed::Fixed(const int num) {
	fixedNum = num << fractionalBits;
}

//De formato no puento fijo a firmato punto fijo
Fixed::Fixed(const float floatValue) {
	fixedNum = roundf(floatValue * (1 << fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

//devuelve los biits que etsban en formato punto fijo
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (fixedNum);
}
//recibe el int en fomrato punto fijo
void Fixed::setRawBits(int const raw) {
	fixedNum = raw;
}

//pasa los bits de formato punto fijo int a formato punto float
float Fixed::toFloat( void ) const {
	float fixedFloat;
	fixedFloat = static_cast<float>(fixedNum) / (1 << fractionalBits);
	return (fixedFloat);
}

//pasa el lost en numero de de point a int normal
int Fixed::toInt( void ) const {
	int ret;
	ret = fixedNum >> fractionalBits;
	return ret;
}