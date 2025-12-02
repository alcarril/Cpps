#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {
			std::cout << "Interface MateriaSource default destrcutor called" << std::endl;
		}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif