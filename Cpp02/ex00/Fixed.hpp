
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		static const int	fractionalBits = 8;
		int					fixedNum;
	public:
		Fixed();
		Fixed(const Fixed& objFixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed& operator=(Fixed& objFix)
		{
			std::cout << "Copy assignment operator called\n";
			if (this == &objFix)
				return (*this);
			if (&this->fixedNum != &objFix.fixedNum)
				this->fixedNum = objFix.fixedNum;
			return (*this);
		}
};

#endif