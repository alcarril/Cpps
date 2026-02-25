
#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include "ex01.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
} ;

#endif