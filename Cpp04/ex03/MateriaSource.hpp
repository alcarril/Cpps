#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

#define MAX_SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _ptrMaterias[MAX_SLOTS];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();
		MateriaSource		&operator=(const MateriaSource& other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
