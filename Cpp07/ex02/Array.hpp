

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template<typename T>
class Array 
{
	private:
		T* _ptrArray;
		unsigned int nElements;
	public:
		Array(): _ptrArray(NULL), nElements(0) {
			std::cout << "Array default constrcutor called\n";
		} ;
		~Array() {
			std::cout << "Array default destructor called\n";
			if (_ptrArray != NULL)
				delete[] _ptrArray;
		} ;
		Array(const Array& copy) {
			std::cout << "Array copy constrcutor called\n";
			this->_ptrArray = NULL;
			this->nElements = 0;
			*this = copy;
		} ;
		Array<T>& operator=(const Array& copy) {
			std::cout << "Array equal operator called\n";
			if (this == &copy)
				return *this;
			if (this->_ptrArray != NULL)
				delete[] _ptrArray;
			this->_ptrArray = new T[copy.nElements];
			for (unsigned int i = 0; i < copy.nElements; i++) {
				this->_ptrArray[i] = copy._ptrArray[i];
			}
			this->nElements = copy.nElements;
			return *this;
		} ;
		Array(unsigned int idx) {
			this->_ptrArray = new T[idx];
			this->nElements = idx;
			std::cout << "Array parameter constrcutor called\n";
		} ;

		//Array specific methods
		unsigned int size(void) const {
			return this->nElements;
		};

		T& operator[](unsigned int index) {
			if (index >= this->nElements)
				throw std::out_of_range("Index out of bounds");
			return _ptrArray[index];
		}
		const T& operator[](unsigned int index) const {
			if (index >= this->nElements)
				throw std::out_of_range("Index out of bounds");
			return _ptrArray[index];
		}
} ;

#endif
