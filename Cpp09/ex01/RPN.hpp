
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
		std::stack<int> result;
		std::string input;

	public:
		RPN();
		~RPN();
		RPN& operator=(const RPN& other) ;
		RPN(const RPN& other) ;

		const std::stack<int>& getStack(void) const;
		void setInput(const std::string& input);
		void DiplayRPN(void) ;
} ;

#endif