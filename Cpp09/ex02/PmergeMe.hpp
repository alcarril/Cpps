
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>*	inputVec;
		std::deque<int>*	inputdeque;
		std::vector<int>	shortVector;
		std::deque<int>		shortDeque;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		void setInputVec(std::vector<int> *_inputPtr);
		void setInputDeque(std::deque<int> *_inputPtr);
		const std::vector<int>& getShortVector(void) const;
		const std::deque<int>& getShortDeque(void) const;

		void mergeInsertionVector(void) ;
		void mergeInsertionDeque(void) ;
} ;

#endif
