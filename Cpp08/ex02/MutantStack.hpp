

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <exception>
#include <algorithm>
#include <stack>
#include <utility>

//Metodos simulados (tener en cuenta que la stack aunque esconga los valores inciales se refire a los del back del constendor, arrays->no rellalloc)
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		//Metodos de clase ortodoxa canonica
		MutantStack() : std::stack<T>() {} // No hace falta porner el constructo de stack pero me apetece
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {} // No hace falta porner el constructo de stack pero me apetece
		MutantStack& operator=(const MutantStack& copy) {
			if (this != &copy)
				this->c = copy.c;
			return *this;
		}
		~MutantStack() {}
		//Metodo clear() es clear() de deque
		void clear(void) {
			this->c.clear();
		}

		class iterator
		{
			private:
				typename std::stack<T>::container_type::iterator it;

			public:
				iterator() {}
				iterator(typename std::stack<T>::container_type::iterator i) : it(i) {}
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
			return iterator(this->c.begin());
		}
		iterator end() {
			return iterator(this->c.end());
		}
};

#endif

