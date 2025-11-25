
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int	fractionalBits = 8;
		int					fixedNum;
	public:
		Fixed();
		Fixed(const Fixed& objFixed);
		Fixed(const int num);//
		Fixed(const float floatValue);//
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;//
		int toInt( void ) const;//
		Fixed& operator=(const Fixed& objFix);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);//?

#endif
