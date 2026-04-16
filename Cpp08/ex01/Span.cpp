

#include "Span.hpp"

Span::Span(void) : vec(), maxElements(0) {}

Span::Span(const int& maxElements) : vec(), maxElements(maxElements) {}

Span::Span(const Span& copy) : vec(copy.vec), maxElements(copy.maxElements) {}

Span::~Span() {}

Span& Span::operator=(const Span& copy) {
	if (this == &copy)
		return *this;
	else {
		if (copy.maxElements <= this->maxElements)
			this->vec = copy.vec; // ya limpiea el vector y ahora lo relleno con los valores del vector del copy
		else {
			this->vec.clear();
			std::vector<int>::const_iterator itCopy = copy.vec.begin();
			for (unsigned int i = 0; i < this->maxElements; i++) {
				this->vec.push_back(*itCopy);
				itCopy++;
			}
		}
	}
	return *this;
}

void Span::addNumber(const int& number) {
	if (vec.size() < maxElements) {
		vec.push_back(number);
		std::sort(vec.begin(), vec.end());
	}
	else 
		throw std::logic_error("Too may elements\n");
}

int Span::longestSpan(void) const {
	if (this->vec.size() == 0 || this->vec.size() == 1) {
		throw std::logic_error("Need more elemets\n");
	}
	int diff = *(this->vec.begin()) - *(this->vec.end() - 1);
	if (diff < 0)
		diff *= -1;
	return diff;
}

int Span::shortestSpan(void) const {
	if (this->vec.size() == 0 || this->vec.size() == 1) {
		throw std::logic_error("Need more elemets\n");
	}
	std::vector<int> aux(this->vec.size());
	std::adjacent_difference(this->vec.begin(), this->vec.end(), aux.begin());
	std::vector<int>::iterator itMin = std::min_element(aux.begin() + 1, aux.end());
	if (*itMin < 0)
		*itMin *= -1;
	std::vector<int>::iterator itMax = std::max_element(aux.begin() + 1, aux.end());
	if (*itMin < *itMax)
		return *itMin;
	else
		return *itMax;
}

void Span::generateRandomNumbers(const unsigned int& n) {
	if (n > this->maxElements)
		throw std::logic_error("Too may elements\n");
	else {
		this->vec.resize(n);
		std::generate(this->vec.begin(), this->vec.end(), std::rand);
		std::sort(this->vec.begin(), this->vec.end());
		// for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); ++it) {
		// 	std::cout << "El valor del numero aleatorio es: " << *it << std::endl;
		// }
	}
}
