#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void iter(T* _ptrArr, const size_t N, Func f) {
	for (size_t i = 0; i < N; i++) {
		f(_ptrArr[i]);
	}
}

template<typename T, typename Func>
void iter2(T* _ptrArr, const size_t N, Func f) {
	for (size_t i = 0; i < N; i++) {
		f(&(_ptrArr[i]));
	}
}


template <typename T>
void increment(T& x) { //no vale para temporales y solo se le pueden pasar variables y objetos no const
	++x;
}

template <typename T>
void print(const T& x) { //vale àra temporales, y variables y objetos const y no const (se trantan comoconst)
	std::cout << x << " ";
}

void appendExclamation(std::string& s) {
	s += "!";
}

template <typename T>
void ptrNoconst(T* ptr) { //se le puede pasar solo cosas no const
	(*ptr)++;
}

template <typename T>
void ptrconst(const T* ptr) { //se le puede pasar cosas const y no const
	std::cout << "El valor del array en la funcion es: " << *ptr << std::endl;
}

#endif