#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int fractionalBits = 8;
		int fixedNum;

	public:
		Fixed();
		Fixed(const Fixed& objFixed);
		Fixed(const int num);
		Fixed(const float floatValue);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed& operator=(const Fixed& objFix);

		// Operadores de flujo
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

		// Operadores de comparación
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Operadores aritméticos
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Operadores de incremento y decremento
		Fixed& operator++();    // Pre-incremento
		Fixed operator++(int);  // Post-incremento
		Fixed& operator--();    // Pre-decremento
		Fixed operator--(int);  // Post-decremento

		// Operadores compuestos
		Fixed& operator+=(const Fixed& other);
		Fixed& operator-=(const Fixed& other);
		Fixed& operator*=(const Fixed& other);
		Fixed& operator/=(const Fixed& other);

		// Funciones estáticas min y max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif
