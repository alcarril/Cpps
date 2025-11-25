#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) {
	// std::cout << "Default constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& objFix) {
	// std::cout << "Copy assignment operator called\n";
	if (this == &objFix)
		return (*this);
	if (&this->fixedNum != &objFix.fixedNum)
		this->fixedNum = objFix.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& objFixed) {
	// std::cout << "Copy constructor called\n";
	this->fixedNum = objFixed.getRawBits();
	// *this = objFixed;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called\n";
}

//devuelve los biits que etsban en formato punto fijo
int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called\n";//?
	return (fixedNum);
}
//recibe el int en fomrato punto fijo
void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits memeber function called\n";//?
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
	// std::cout << "Int constructor called\n";
	fixedNum = num << fractionalBits;
}

//De formato floating.point fijo a firmato fixed.pointfijo->P1.B
//multiplicar por 256 2^8 pero desde moviendo bits
Fixed::Fixed(const float floatValue) {
	// std::cout << "Float constructor called\n";
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

bool Fixed::operator>(const Fixed& other) const { return this->fixedNum > other.fixedNum; }
bool Fixed::operator<(const Fixed& other) const { return this->fixedNum < other.fixedNum; }
bool Fixed::operator>=(const Fixed& other) const { return this->fixedNum >= other.fixedNum; }
bool Fixed::operator<=(const Fixed& other) const { return this->fixedNum <= other.fixedNum; }
bool Fixed::operator==(const Fixed& other) const { return this->fixedNum == other.fixedNum; }
bool Fixed::operator!=(const Fixed& other) const { return this->fixedNum != other.fixedNum; }


//En las operaciones aritmetica conviene devover un objeto nuevo, si fuesen
//operaciones aritmticas con igualacion no haria falta hacerlo, se podrai modificar
//el porpio objeto this.
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.fixedNum = this->fixedNum + other.fixedNum;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.fixedNum = this->fixedNum - other.getRawBits();
	return result;
}

//a*b*factor =/ (a*factor) * (b*factor) = a*b*factor² -> a*b*factor² / factor 
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.fixedNum = (this->fixedNum * other.getRawBits()) >> fractionalBits;
	return result;
}

//a/b*factor =/ (a/factor) / (b/factor) = a/b  -> a/b * factor
Fixed Fixed::operator/(const Fixed& other) const {
	if (other.fixedNum == 0) {
		throw std::runtime_error("Division by zero");
	}
	Fixed result;
	result.fixedNum = (this->fixedNum << fractionalBits) / other.getRawBits();
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
