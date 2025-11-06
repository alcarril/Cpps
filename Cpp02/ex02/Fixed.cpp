#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& objFixed) : fixedNum(objFixed.fixedNum) {
	// std::cout << "Copy constructor called\n";
}

// Pasa de int a formato punto fijo
Fixed::Fixed(const int num) {
	fixedNum = num << fractionalBits;
}

// De formato float a formato punto fijo
Fixed::Fixed(const float floatValue) {
	fixedNum = roundf(floatValue * (1 << fractionalBits));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called\n";
}

// Devuelve los bits en formato punto fijo
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (fixedNum);
}

// Recibe el int en formato punto fijo
void Fixed::setRawBits(int const raw) {
	fixedNum = raw;
}

// Pasa los bits de formato punto fijo a float
float Fixed::toFloat(void) const {
	float fixedFloat;
	fixedFloat = static_cast<float>(fixedNum) / (1 << fractionalBits);
	return (fixedFloat);
}

// Pasa los bits de formato punto fijo a int
int Fixed::toInt(void) const {
	int ret;
	ret = fixedNum >> fractionalBits;
	return ret;
}

Fixed& Fixed::operator=(const Fixed& objFix) {
	std::cout << "Copy assignment operator called\n";
	if (this == &objFix)
		return (*this);
	this->fixedNum = objFix.fixedNum;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& other) const { return this->fixedNum > other.fixedNum; }
bool Fixed::operator<(const Fixed& other) const { return this->fixedNum < other.fixedNum; }
bool Fixed::operator>=(const Fixed& other) const { return this->fixedNum >= other.fixedNum; }
bool Fixed::operator<=(const Fixed& other) const { return this->fixedNum <= other.fixedNum; }
bool Fixed::operator==(const Fixed& other) const { return this->fixedNum == other.fixedNum; }
bool Fixed::operator!=(const Fixed& other) const { return this->fixedNum != other.fixedNum; }

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.fixedNum = this->fixedNum + other.fixedNum;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.fixedNum = this->fixedNum - other.fixedNum;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.fixedNum = (this->fixedNum * other.fixedNum) >> fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other.fixedNum == 0) {
		throw std::runtime_error("Division by zero");
	}
	Fixed result;
	result.fixedNum = (this->fixedNum << fractionalBits) / other.fixedNum;
	return result;
}

// Pre-incremento
Fixed& Fixed::operator++() {
	this->fixedNum++;
	return *this;
}

// Post-incremento
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->fixedNum++;
	return temp;
}

// Pre-decremento
Fixed& Fixed::operator--() {
	this->fixedNum--;
	return *this;
}

// Post-decremento
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->fixedNum--;
	return temp;
}

Fixed& Fixed::operator+=(const Fixed& other) {
	this->fixedNum += other.fixedNum;
	return *this;
}

Fixed& Fixed::operator-=(const Fixed& other) {
	this->fixedNum -= other.fixedNum;
	return *this;
}

Fixed& Fixed::operator*=(const Fixed& other) {
	this->fixedNum = (this->fixedNum * other.fixedNum) >> fractionalBits;
	return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
	if (other.fixedNum == 0)
		throw std::runtime_error("Division by zero");
	long tmp = (this->fixedNum << fractionalBits);
	tmp /= other.fixedNum;
	this->fixedNum = tmp;
	return *this;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}