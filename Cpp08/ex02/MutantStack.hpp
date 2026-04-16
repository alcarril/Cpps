

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <exception>
#include <algorithm>
#include <stack>

//Metodos simulados (tener en cuenta que la stack aunque esconga los valores inciales se refire a los del back del constendor, arrays->no rellalloc)
template<typename T>
class MutantStack : public std::stack<T>
{
	private:
		std::deque<T> deq;

	public:
		//Metodos de clase ortodoxa canonica
		MutantStack() : deq() {}
		MutantStack(const MutantStack& copy) : deq(copy.deq) {}
		MutantStack& operator=(const MutantStack& copy) {
			if (this != &copy)
				deq = copy.deq;
			return *this;
		}
		~MutantStack() {}
		//Metodo push es como un push_back
		void push(const T& value) {
			this->deq.push_back(value);
		}
		//Metodo pop() es como un pop_back()
		void pop(void) {
			this->deq.pop_back();
		}
		//Metodo size es como un size()
		size_t size(void) const {
			return this->deq.size();
		}
		//Metodo Empty es como un empty()
		bool empty(void) const {
			if (this->size() == 0)
				return true;
			else
				return false;
		}
		//Metodo top() es como un back() o devolver un end - 1, se devuleve referencia para poder editar su valor originañl
		T& top(void) {
			return this->deq.back();
		}
		//Metodo clear() es clear() de deque
		void clear(void) {
			this->deq.clear();
		}

		class iterator
		{
			private:
				typename std::deque<T>::iterator it;

			public:
				iterator() {}
				iterator(typename std::deque<T>::iterator i) : it(i) {}
				iterator& operator=(const iterator& other) {
					it = other.it;
					return *this;
				}
				T& operator*() const { //Devolvemos direccion el valor al que apunta it por referencia para poder concatenar y para poder editar con *it= algo
					return *it;
				}
				T* operator->() const { //Como it  no es un puntero perse, hay que usar la notacion para savar el valro y del la direccion
					return &(*it);
				}
				iterator& operator++() {//Operador de preincremento, como ya hemos igualado con it (object), solo hay que usar la notacion de aumento
					++it;
					return *this;
				}
				iterator operator++(int) {//Operador de postincremento, cconservamos el valor en un temporal, incrementeamos it perod evolvemos el temporal
					iterator temp(*this);
					++it;
					return temp;
				}
				iterator& operator--() { //operador de predcremento
					--it;
					return *this;
				}
				iterator operator--(int) { //operador de postdecremento
					iterator temp(*this);
					--it;
					return temp;
				}
				bool operator==(const iterator& other) const { //Operador de comparacion, comparamos este it ya creado con otro
					return it == other.it;
				}
				bool operator!=(const iterator& other) const { //operador de diferencuas, comparamos este it ya creado con otro
					return it != other.it;
				}
		};
		//Metodo de begin, usamos el iterador de deque original, para construir un objeto iterator de mi clase a trve de el y devolverlo
		//No devolvemos un objeto de.begin() ->iteraror porque queremos que cunado usemos el metodo de mutantstack nos devulva un objeto
		//tipo mutanstack::iterator.
		iterator begin() { 
			return iterator(deq.begin());
		}
		iterator end() {
			return iterator(deq.end());
		}
};

#endif