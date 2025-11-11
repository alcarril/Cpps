


#include "FragTrap.hpp"

//flagtrap default constructor
FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	name = "Default FlagTrap";
	std::cout << "FlagTrap default constructor called\n";
}

//flagtrap parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FlagTrap parameterized constructor called for " << name << "\n";
}
//flagtrap destructor
FragTrap::~FragTrap() {
	std::cout << "FlagTrap destructor called for " << name << "\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FlagTrap copy constructor called for " << copy.name << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	name = copy.name;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Hi five guys!!!\n";
}
