

#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& objFixed) : fixedNum(objFixed.fixedNum) {
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (fixedNum);
}

void Fixed::setRawBits(int const raw) {
	fixedNum = raw;
}
