#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#define MAX_IDEAS 100

class	Brain
{
	private:
		std::string _ideas[MAX_IDEAS];

	public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		void setIdeas(const std::string (&newIdeas)[MAX_IDEAS]);
		const std::string (&getIdeas(void) const)[MAX_IDEAS];
} ;

#endif
