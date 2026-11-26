
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->inputdeque = other.inputdeque;
		this->inputVec = other.inputVec;
		this->shortVector = other.getShortVector();
		this->shortDeque = other.getShortDeque();
	}
	return *this;
}

void PmergeMe::setInputVec(std::vector<int> *_inputPtr) {
	this->inputVec = _inputPtr;
}
void PmergeMe::setInputDeque(std::deque<int> *_inputPtr) {
	this->inputdeque = _inputPtr;
}

const std::vector<int>& PmergeMe::getShortVector(void) const {
	return this->shortVector;
}

const std::deque<int>& PmergeMe::getShortDeque(void) const {
	return this->shortDeque;
}

//

static void binaryInsertVector(std::vector<int>& sorted, int value)
{
	int left = 0;
	int right = sorted.size();
	while (left < right) {
		int range = (right - left) / 2;
		int mid = left + range;
		if (value < sorted[mid])
			right = mid;
		else
			left = mid + 1;
	}
	sorted.insert(sorted.begin() + left, value);
}

std::vector<int> PmergeMe::mergeInsertVectorRec(std::vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	std::vector<int> big;
	std::vector<int> small;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (i + 1 < arr.size())
		{
			if (arr[i] < arr[i + 1]) {
				small.push_back(arr[i]);
				big.push_back(arr[i + 1]);
			}
			else {
				small.push_back(arr[i + 1]);
				big.push_back(arr[i]);
			}
		}
		else
			big.push_back(arr[i]);
	}
	this->shortVector = mergeInsertVectorRec(big);
	for (size_t i = 0; i < small.size(); ++i)
		binaryInsertVector(this->shortVector, small[i]);
	return this->shortVector;
}


static void binaryInsertDeque(std::deque<int>& sorted, int value)
{
	int left = 0;
	int right = sorted.size();
	while (left < right) {
		int range = (right - left) / 2;
		int mid = left + range;
		if (value < sorted[mid])
			right = mid;
		else
			left = mid + 1;
	}
	sorted.insert(sorted.begin() + left, value);
}

std::deque<int> PmergeMe::mergeInsertDequeRec(std::deque<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	std::deque<int> big;
	std::deque<int> small;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (i + 1 < arr.size())
		{
			if (arr[i] < arr[i + 1]) {
				small.push_back(arr[i]);
				big.push_back(arr[i + 1]);
			}
			else {
				small.push_back(arr[i + 1]);
				big.push_back(arr[i]);
			}
		}
		else
			big.push_back(arr[i]);
	}

	this->shortDeque = mergeInsertDequeRec(big);
	for (size_t i = 0; i < small.size(); ++i)
		binaryInsertDeque(this->shortDeque, small[i]);
	return this->shortDeque;
}

void PmergeMe::mergeInsertionVector(void) {
	this->startVector = clock();
	mergeInsertVectorRec(*this->inputVec);
	this->endVector = clock();
}

void PmergeMe::mergeInsertionDeque(void) {
	this->startDeque = clock();
	mergeInsertDequeRec(*this->inputdeque);
	this->endDeque = clock();
}

