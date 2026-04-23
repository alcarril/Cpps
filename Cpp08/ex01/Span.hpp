

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ctime>
#include <exception>
#include <algorithm>
#include <set>
#include <vector>
#include <numeric>

class Span
{
	private:
		std::vector<int> vec;
		const unsigned int maxElements;
	public:
		Span();
		Span(const int& maxElements);
		Span(const Span& copy);
		Span & operator=(const Span& copy);
		~Span();
		
		void addNumber(const int& number);
		int shortestSpan() const;
		int longestSpan() const;
		void generateRandomNumbers(const unsigned int& n);

} ;

#endif