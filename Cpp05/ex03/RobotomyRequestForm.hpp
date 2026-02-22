#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		//methods
		void execute(const Bureaucrat& executor) const;
};

#endif