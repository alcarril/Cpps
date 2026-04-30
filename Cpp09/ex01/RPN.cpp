

#include "RPN.hpp"

RPN::RPN() {} ;

RPN::~RPN() {} ;

RPN::RPN(const RPN& other) {
	if (this != &other)
		*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	this->input = other.input;
	this->result = other.result;
	return *this;
}

const std::stack<int>& RPN::getStack(void) const {
	return this->result;
}

void RPN::setInput(const std::string& input) {
	this->input = input;
}

void RPN::DiplayRPN(void) {
	std::stringstream ss(this->input);
	std::string lex;
	for (;ss >> lex;) {
		int op1;
		int op2;
		if (lex.length() > 1)
			throw std::logic_error("Error\n");
		else if (isdigit(static_cast<char>(lex[0]))) {
			this->result.push(atoi(lex.c_str()));
		}
		else if (lex[0] != '*' && lex[0] != '/' && lex[0] != '+' && lex[0] != '-') {
			throw std::logic_error("Error\n");
		}
		else if (this->result.size() < 2)
			throw std::logic_error("Error\n");
		else if (lex[0] == '*') {
			op1 = this->result.top();
			this->result.pop();
			op2 = this->result.top();
			this->result.pop();
			this->result.push(op2 * op1);
		}
		else if (lex[0] == '/') {
			op1 = this->result.top();
			this->result.pop();
			op2 = this->result.top();
			this->result.pop();
			this->result.push(op2 / op1);
		}
		else if (lex[0] == '+') {
			op1 = this->result.top();
			this->result.pop();
			op2 = this->result.top();
			this->result.pop();
			this->result.push(op2 + op1);
		}
		else if (lex[0] == '-') {
			op1 = this->result.top();
			this->result.pop();
			op2 = this->result.top();
			this->result.pop();
			this->result.push(op2 - op1);
		}
		else
			throw std::logic_error("Error\n");
		lex.clear();
	}
	if (this->result.size() != 1)
		throw std::logic_error("Error\n");
	std::cout << result.top() << std::endl;
}
