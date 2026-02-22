#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

/*
	sigle responsability, 
	Clases anidadas -> encapulacion de diseño y principio de cohesion
*/
//principios de diseño:
class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		Bureaucrat& 		operator=(const Bureaucrat& copy);
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		const int&			getGrade(void) const;
		const std::string&	getName(void) const;
		void				upGrade(void);
		void				downGrade(void);

		class GradeTooHighException : public std::exception
		{
			private:
				std::string msg;
			public:
				GradeTooHighException();
				GradeTooHighException(const std::string &name);
				virtual const char* what() const throw();
				~GradeTooHighException() throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string msg;
			public:
				GradeTooLowException();
				GradeTooLowException(const std::string &name);
				virtual const char* what() const throw();
				~GradeTooLowException() throw();
		};
} ;

//operador de sobrecagar
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
