
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
		std::deque<int> mergeInsertDequeRec(std::deque<int> arr);
		std::vector<int> mergeInsertVectorRec(std::vector<int> arr);
		const std::vector<int>& getShortVector(void) const;
		const std::deque<int>& getShortDeque(void) const;

		void mergeInsertionVector(void) ;
		void mergeInsertionDeque(void) ;
		clock_t startDeque;
		clock_t endDeque;
		clock_t startVector;
		clock_t endVector;
} ;

#endif
