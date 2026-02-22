
#include "AForm.hpp"

AForm::AForm() : name("Default AForm"), sign(false), gradeToSign(1), gradeToExecute (1) {
	std::cout << "AForm default constrcutor called" << std::endl;
}

AForm::AForm(const std::string& name, const int& gradeToSing, const int& gradeToExecute) : 
	name(name), sign(false), gradeToSign(gradeToSing), gradeToExecute(gradeToExecute) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException(this->getName());
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException(this->getName());
	std::cout << "AForm " << this->getName() << " created with grade to sign " << this->getGradeToSign() << " and grade to execute " << this->getGradeToExecute() << std::endl;
}

AForm::AForm(const AForm& copy) : 
	name(copy.name), sign(copy.sign), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy) {
		this->sign = copy.sign;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destrcutor called\n";
}

const std::string& AForm::getName(void) const {
	return this->name;
}	

const bool& AForm::getSign(void) const {
	return this->sign;
}

const int& AForm::getGradeToSign(void) const {
	return this->gradeToSign;
}

const int& AForm::getGradeToExecute(void) const {
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException(this->getName());
	if (this->getSign() == true)
		throw AForm::IsSignedException(this->getName());
	this->sign = true;
}

void AForm::singForm(const Bureaucrat& b) {
	try {
		this->beSigned(b);
	} catch (std::exception& e) {
		std::cerr << "Bureaucrat " << b.getName() << " couldn't sign ";
		std::cout << this->getName() << " AForm because: ";
		std::cout << e.what();
		return ;
	}
	std::cout << "Bureaucrat " << b.getName() << " signed " << this->getName() << " AForm\n";
}

void AForm::execute(const Bureaucrat& executor) const {
	if (this->getSign() == false)
		throw AForm::IsNotSignedException(this->getName());
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException(executor.getName());
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << " AForm ";
	if (f.getSign() == true) {
		os << "is signed, ";
	} else {
		os << "is not signed, ";
	}
	os << "grade to sign " << f.getGradeToSign() << " and grade to execute " << f.getGradeToExecute() << std::endl;
	return os;
}

//Exception for when the grade is too high
AForm::GradeTooHighException::GradeTooHighException() {
	std::cout << "AForm Grade Too High Execption default contructor called\n";
	this->msg = "";
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& name) {
	std::string msg;
	msg = "AForm " + name + " grade requirements are over the admited range\n";
	this->msg = msg;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return this->msg.c_str();
}


AForm::GradeTooHighException::~GradeTooHighException() throw() {
	std::cout << "AForm exception destroyed\n";
}

//Exception for when the grade is too low
AForm::GradeTooLowException::GradeTooLowException() {
	std::cout << "AForm Grade Too Low Execption default contructor called\n";
	this->msg = "";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &name) {
	std::string msg;
	msg = "AForm " + name + " grade requirements are under the admited range\n";
	this->msg = msg;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return this->msg.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
	std::cout << "AForm exception destroyed\n";
}

//Exception for when the AForm is already signed
AForm::IsSignedException::IsSignedException() {
	std::cout << "AForm Is Signed Execption default contructor called\n";
	this->msg = "";
}

AForm::IsSignedException::IsSignedException(const std::string &name) {
	std::string msg;
	msg = "AForm " + name + " is already signed\n";
	this->msg = msg;
}

AForm::IsSignedException::~IsSignedException() throw() {
	std::cout << "AForm exception destroyed\n";
}

const char* AForm::IsSignedException::what() const throw() {
	return this->msg.c_str();
}

//Exception when the fprm is not signed for execution
AForm::IsNotSignedException::IsNotSignedException() {
	std::cout << "AForm Is Not Signed Execption default contructor called\n";
	this->msg = "";
}

AForm::IsNotSignedException::IsNotSignedException(const std::string &name) {
	std::string msg;
	msg = "AForm " + name + " is not signed for execution\n";
	this->msg = msg;
}

const char* AForm::IsNotSignedException::what() const throw() {
	return this->msg.c_str();
}

AForm::IsNotSignedException::~IsNotSignedException() throw() {
	std::cout << "AForm exception destroyed\n";
}