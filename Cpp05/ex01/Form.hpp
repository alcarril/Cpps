
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
		Form& operator=(const Form& copy);

	public:
		Form();
		Form(const std::string& name, const int& gradeToSing, const int& gradeToExecute);
		Form(const Form& copy);
		~Form();

		//getters
		const std::string& getName(void) const;
		const bool& getSign(void) const;
		const int& getGradeToSign(void) const;
		const int& getGradeToExecute(void) const;

		//methods
		void beSigned(const Bureaucrat& b);

		//excetion classes
		class GradeTooHighException : public std::exception 
		{
			private:
				std::string msg;
			public:
				GradeTooHighException();
				GradeTooHighException(const std::string& name);
				const char* what() const throw();
				~GradeTooHighException() throw();
		} ;

		class GradeTooLowException : public std::exception
		{
			private:
				std::string msg;
			public:
				GradeTooLowException();
				GradeTooLowException(const std::string &name);
				virtual const char* what() const throw();
				~GradeTooLowException() throw();
		} ;

		class IsSignedException : public std::exception
		{
			private:
				std::string msg;
			public:
				IsSignedException();
				IsSignedException(const std::string &name);
				virtual const char* what() const throw();
				~IsSignedException() throw();
		} ;
} ;

//oveloading ostream operator
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif