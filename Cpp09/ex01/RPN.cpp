

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
		if (lex.length() > 1) //comporbar que no es un numero mayor que 10
			throw std::logic_error("Error\n");
		else if (isdigit(static_cast<char>(lex[0]))) { //comporbar que es un numero
			this->result.push(atoi(lex.c_str()));
		}
		else if (lex[0] != '*' && lex[0] != '/' && lex[0] != '+' && lex[0] != '-') { //comprobar que es un operador valido
			throw std::logic_error("Error\n");
		}
		else if (this->result.size() < 2) //comprobar que almenos hay dos operandos para poder hacer una operacion
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
	if (this->result.size() != 1) { //comprobar que al final no hay mas de un numero en la pila: ni nuemros ni operadores
		throw std::logic_error("Error\n");
	}
	std::cout << this->result.top() << std::endl;
}
