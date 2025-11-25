

#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	std::cout << "Default constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& objFix)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &objFix)
		return (*this);
	if (&this->fixedNum != &objFix.fixedNum)
		this->fixedNum = objFix.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& objFixed) {
	std::cout << "Copy constructor called\n";
	// this->fixedNum = objFixed.getRawBits();
	*this = objFixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (fixedNum);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	fixedNum = raw;
}
