
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default constructor called\n";
	this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm constructor called\n";
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm copy constructor called\n";
	this->target = copy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy) {
		this->target = copy.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	static int counter;
	AForm::execute(executor);
	try {
		counter++;
		if (counter % 2 == 0) {
			std::cout << this->target << " has been robotomized succesfully\n";
		}
		else {
			throw std::logic_error("Robotomy failed!");
		}
	} catch (const std::logic_error& e) {
		std::cerr << e.what();
	}
}
