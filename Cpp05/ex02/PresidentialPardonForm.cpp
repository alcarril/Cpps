
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
	std::cout << "PresidentialPardonForm default constructor called\n";
	this->target = "";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm constructor called\n";
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm copy constructor called\n";
	this->target = copy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy) {
		this->target = copy.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
}

