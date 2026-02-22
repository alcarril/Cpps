
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
		AForm& operator=(const AForm& copy);

	public:
		AForm();
		AForm(const std::string& name, const int& gradeToSing, const int& gradeToExecute);
		AForm(const AForm& copy);
		virtual ~AForm();

		//getters
		const std::string& getName(void) const;
		const bool& getSign(void) const;
		const int& getGradeToSign(void) const;
		const int& getGradeToExecute(void) const;

		//methods
		void beSigned(const Bureaucrat& b);
		void singForm(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;

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

		class IsNotSignedException : public std::exception
		{
			private:
				std::string msg;
			public:
				IsNotSignedException();
				IsNotSignedException(const std::string &name);
				virtual const char* what() const throw();
				~IsNotSignedException() throw();
		} ;
} ;

//oveloading ostream operator
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif