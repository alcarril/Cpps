
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
		Fixed operator=(Fixed objFix)
		{
			std::cout << "Copy assignment operator called\n";
			if (this == &objFix)
				return (*this);
			if (&this->fixedNum != &objFix.fixedNum)
				this->fixedNum = objFix.fixedNum;
			return (*this);
		}
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
		{
			os << fixed.toFloat();
			return os;
		}
};

#endif
