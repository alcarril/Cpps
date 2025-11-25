

#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	std::cout << "Default constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& objFix) {
	std::cout << "Copy assignment operator called\n";
	if (this == &objFix)
		return (*this);
	if (&this->fixedNum != &objFix.fixedNum)
		this->fixedNum = objFix.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& objFixed) {
	std::cout << "Copy constructor called\n";
	this->fixedNum = objFixed.getRawBits();
	// *this = objFixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

//devuelve los biits que etsban en formato punto fijo
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";//?
	return (fixedNum);
}
//recibe el int en fomrato punto fijo
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits memeber function called\n";//?
	fixedNum = raw;
}

//Ampliamos (sobrecargamos) el operador de ofstream para nuestra clase
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

//pasa de int a fixed.point format->P1.A
//multiplicar por 256 2^8 pero desde moviendo bit
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	fixedNum = num << fractionalBits;
}

//De formato floating.point fijo a firmato fixed.pointfijo->P1.B
//multiplicar por 256 2^8 pero desde moviendo bits
Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called\n";
	fixedNum = roundf(floatValue * (1 << fractionalBits));
}

//pasa los bits de formato fixed.point a floatiin.point
//dividir entre 256 2^8 pero desde moviendo bits
float Fixed::toFloat( void ) const {
	float fixedFloat;
	fixedFloat = static_cast<float>(fixedNum) / (1 << fractionalBits);
	return (fixedFloat);
}

//pasa el lost en numero fixed.point a int
//dividir entre 256 2^8 pero desde moviendo bits
int Fixed::toInt( void ) const {
	int ret;
	ret = fixedNum >> fractionalBits;
	return ret;
}
