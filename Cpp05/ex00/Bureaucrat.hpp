#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		unsigned int getGrade(void) const;
		std::string getName(void) const;
} ;

#endif