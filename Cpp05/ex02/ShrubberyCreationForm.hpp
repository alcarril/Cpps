#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;
};

#endif