

#include "PmergeMe.hpp"
#include <algorithm>

template <typename T>
void printContainerformat(const T& containerBef, const T& containerAf)
{
	std::cout << "Before: ";
	int i = 0;
	typename T::const_iterator itBef = containerBef.begin();
	for (; itBef != containerBef.end() && i < 5; ++itBef) {
		if (i == 4 && containerBef.size() > 5){
			std::cout << "[...]";
			break;
		}
		std::cout << *itBef << " ";
		i++;
	}
	std::cout << std::endl;
	std::cout << "After:  ";
	i = 0;
	typename T::const_iterator itAf = containerAf.begin();
	for (; itAf != containerAf.end() && i < 5; ++itAf) {
		if (i == 4 && containerAf.size() > 5) {
			std::cout << "[...]";
			break;
		}
		std::cout << *itAf << " ";
		i++;
	}
	std::cout << std::endl;
}

int main(int argz, char **argv)
{
	if (argz == 1) {
		std::cerr << "Need more arguments\n";
		return 1 ;
	}
	std::vector<int> inputVec;
	std::deque<int> inputDeque;
	for (int i = 1; argv[i] != NULL; i++) {
		int value;
		std::stringstream ss(argv[i]);
		ss >> value;
		if (ss.fail() || value < 0 || !ss.eof()) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		std::vector<int>::iterator it = std::find(inputVec.begin(), inputVec.end(), value);
		if (it != inputVec.end())
			continue ;
		inputVec.push_back(value);
		inputDeque.push_back(value);
	}
	if (inputVec.size() == 1) {
		std::cout << "Before: " << inputVec[0] << std::endl;
		std::cout << "After:  " << inputVec[0] << std::endl;
		std::cout << "Time to process a range of 1 elements with std::vector : 0.00000 us" << std::endl;
		std::cout << "Time to process a range of 1 elements with std::deque  : 0.00000 us" << std::endl;
		return 0;
	}

	PmergeMe m;
	m.setInputDeque(&inputDeque);
	m.setInputVec(&inputVec);


	m.mergeInsertionVector();
	double timeVec = (double)(m.endVector - m.startVector) / CLOCKS_PER_SEC * 1000000.0;

	m.mergeInsertionDeque();
	double timeDeque = (double)(m.endDeque - m.startDeque) / CLOCKS_PER_SEC * 1000000.0;

	const std::vector<int>& sortedVec = m.getShortVector();
	const std::deque<int>& sortedDeque = m.getShortDeque();
	printContainerformat(inputVec, sortedVec);
	// printContainerformat(inputDeque, sortedDeque); -> Subject format

	std::cout << "Time to process a range of " << sortedVec.size()
			<< " elements with std::vector : "
			<< std::fixed << std::setprecision(5)
			<< timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << sortedDeque.size()
			<< " elements with std::deque  : "
			<< std::fixed << std::setprecision(5)
			<< timeDeque << " us" << std::endl;
	return 0;
}
