

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

	PmergeMe m;
	m.setInputDeque(&inputDeque);
	m.setInputVec(&inputVec);

	clock_t startVec = clock();
	m.mergeInsertionVector();
	clock_t endVec = clock();

	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	clock_t startDeque = clock();
	m.mergeInsertionDeque();
	clock_t endDeque = clock();

	double timeDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

	const std::vector<int>& sortedVec = m.getShortVector();
	const std::deque<int>& sortedDeque = m.getShortDeque();
	printContainerformat(inputVec, sortedVec);
	// printContainerformat(inputDeque, sortedDeque); ->Formato enunciado

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
