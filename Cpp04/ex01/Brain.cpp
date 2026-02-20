#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constrcutor called" << std::endl;
	for(int i = 0; i < MAX_IDEAS; i++) {
		_ideas[i] = "Default idea";
	}
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constrcutor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain default destrcutor called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		int _nIdeas = sizeof(_ideas) / sizeof(std::string);
		const std::string (&copyIdeas)[MAX_IDEAS] = copy.getIdeas();
		for (int i = 0; i < _nIdeas; i++) {
			_ideas[i] = copyIdeas[i];
		}
		return *this;
	}
}

// opcion dos usadno sette y getter
// Brain& Brain::operator=(const Brain& copy) {
// 	std::cout << "Brain copy operator called" << std::endl;
// 	if (this == &copy)
// 		return *this;
// 	else {
// 		this->setIdeas(copy.getIdeas());
// 		return *this;
// 	}
// }

//se podria habeer usado un getter se refrencia en const
const std::string (&Brain::getIdeas(void) const)[MAX_IDEAS] {
	return _ideas;
}

void Brain::setIdeas(const std::string (&newIdeas)[MAX_IDEAS]) {
	for (int i = 0; i < MAX_IDEAS; i++) {
		this->_ideas[i] = newIdeas[i];
	}
}
