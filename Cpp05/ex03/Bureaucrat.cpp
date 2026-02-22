
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(1) {
	std::cout << "Bureucrat default constrcutor called" << std::endl;
}

Bureaucrat::Bureaucrat (const std::string &name, const int &grade) : name(name), grade(grade) {
	if (this->grade < 1)
		throw GradeTooHighException(this->getName());
	else if (this->grade > 150)
		throw GradeTooLowException(this->getName());
	std::cout << "Bureaucrat " << this->getName() << " created with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : 
	name(copy.name), grade(copy.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
		if (this != &copy) {
			this->grade = copy.grade;
		}
		return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destrcutor called\n";
}


const int& Bureaucrat::getGrade(void) const {
	return this->grade;
}

const std::string&  Bureaucrat::getName(void) const {
	return this->name;
}

void Bureaucrat::upGrade(void) {
	try {
		if (this->getGrade() == 1)
			throw GradeTooHighException(this->getName());
		else {
			this->grade--;
			std::cout << "Bureaucrat " << this->getName() << " upgraded to grade " << this->getGrade() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::downGrade(void) {
	try {
		if (this->getGrade() == 150)
			throw Bureaucrat::GradeTooLowException(this->getName());
		else {
			this->grade++;
			std::cout << "Bureaucrat " << this->getName() << " downgraded to grade " << this->getGrade() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << e.what();
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << "Burearcrat " << this->getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " because " << e.what();
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {
	msg = "";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name) {
	msg = "Bureaucrat " + name + " grade is to high\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return this->msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	std::cout << "Exception destruyed\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
	msg = "";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) {
	msg = "Bureaucrat " + name + " grade is to low\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return this->msg.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	std::cout << "Exception destruyed\n";
}
