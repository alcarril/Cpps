
#include "Form.hpp"

Form::Form() : name("Default form"), sign(false), gradeToSign(1), gradeToExecute (1) {
	std::cout << "Form default constrcutor called" << std::endl;
}

Form::Form(const std::string& name, const int& gradeToSing, const int& gradeToExecute) : 
	name(name), sign(false), gradeToSign(gradeToSing), gradeToExecute(gradeToExecute) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException(this->getName());
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException(this->getName());
	std::cout << "Form " << this->getName() << " created with grade to sign " << this->getGradeToSign() << " and grade to execute " << this->getGradeToExecute() << std::endl;
}

Form::Form(const Form& copy) : 
	name(copy.name), sign(copy.sign), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy) {
		this->sign = copy.sign;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destrcutor called\n";
}

const std::string& Form::getName(void) const {
	return this->name;
}	

const bool& Form::getSign(void) const {
	return this->sign;
}

const int& Form::getGradeToSign(void) const {
	return this->gradeToSign;
}

const int& Form::getGradeToExecute(void) const {
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException(this->getName());
	if (this->getSign() == true)
		throw Form::IsSignedException(this->getName());
	this->sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << " form ";
	if (f.getSign() == true) {
		os << "is signed, ";
	} else {
		os << "is not signed, ";
	}
	os << "grade to sign " << f.getGradeToSign() << " and grade to execute " << f.getGradeToExecute() << std::endl;
	return os;
}

//Exception for when the grade is too high
Form::GradeTooHighException::GradeTooHighException() {
	std::cout << "Form Grade Too High Execption default contructor called\n";
	this->msg = "";
}

Form::GradeTooHighException::GradeTooHighException(const std::string& name) {
	std::string msg;
	msg = "Form " + name + " grade requirements are over the admited range\n";
	this->msg = msg;
}

const char* Form::GradeTooHighException::what() const throw() {
	return this->msg.c_str();
}


Form::GradeTooHighException::~GradeTooHighException() throw() {
	std::cout << "Form exception destroyed\n";
}

//Exception for when the grade is too low
Form::GradeTooLowException::GradeTooLowException() {
	std::cout << "Form Grade Too Low Execption default contructor called\n";
	this->msg = "";
}

Form::GradeTooLowException::GradeTooLowException(const std::string &name) {
	std::string msg;
	msg = "Form " + name + " grade requirements are under the admited range\n";
	this->msg = msg;
}

const char* Form::GradeTooLowException::what() const throw() {
	return this->msg.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
	std::cout << "Form exception destroyed\n";
}

//Exception for when the form is already signed
Form::IsSignedException::IsSignedException() {
	std::cout << "Form Is Signed Execption default contructor called\n";
	this->msg = "";
}

Form::IsSignedException::IsSignedException(const std::string &name) {
	std::string msg;
	msg = "Form " + name + " is already signed\n";
	this->msg = msg;
}

Form::IsSignedException::~IsSignedException() throw() {
	std::cout << "Form exception destroyed\n";
}

const char* Form::IsSignedException::what() const throw() {
	return this->msg.c_str();
}