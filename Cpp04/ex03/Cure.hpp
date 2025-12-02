#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		Cure(std::string const & type);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif