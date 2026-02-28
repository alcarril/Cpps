#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void iter(T* _ptrArr, const size_t N, Func f) {
	for (size_t i = 0; i < N; i++) {
		f(_ptrArr[i]);
	}
}

template <typename T>
void increment(T& x) {
	++x;
}

template <typename T>
void print(const T& x) {
	std::cout << x << " ";
}

void append_exclamation(std::string& s) {
	s += "!";
}

#endif