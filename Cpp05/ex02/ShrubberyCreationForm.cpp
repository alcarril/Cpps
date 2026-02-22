
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default constructor called\n";
	this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called\n";
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called\n";
	this->target = copy.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy) {
		this->target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::fstream file((this->target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	try {
		if (!file.is_open())
			throw std::runtime_error("Cannot open file\n");
	} catch (const std::runtime_error& e) {
		std::cerr << "Error creating file: " << e.what();
		return ;
	}
	file << "      ^\n"
	"     /|\\\n"
	"    //|\\\\\n"
	"   ///|\\\\\\\n"
	"      |\n";
	file.close();
}
