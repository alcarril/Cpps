#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "AForm.hpp"


class AForm;

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

		//getters
		const int&			getGrade(void) const;
		const std::string&	getName(void) const;

		//methods
		void	upGrade(void);
		void	downGrade(void);
		void 	signForm(AForm& form) const;
		void 	executeForm(AForm const & form) const;

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
