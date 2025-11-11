#include "ClapTrap.hpp"

//Default constructor
ClapTrap::ClapTrap() :
	hitPoints(10), 
	energyPoints(10), 
	attackDamage(0), 
	name("Default")
{
	std::cout << "ClapTrap default constructor called\n";
}
//Default parameter constrcutor
ClapTrap::ClapTrap(const std::string &name) : 
	hitPoints(10), energyPoints(10), attackDamage(0), name(name) {
	std::cout << "ClapTrap parameter constructor called\n";
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& copy) 
	: hitPoints(copy.hitPoints), 
	energyPoints(copy.energyPoints),
	attackDamage(copy.attackDamage), 
	name(copy.name) {
	std::cout << "ClapTrap copy constructor called\n";
}

//Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " default destructor called\n";
}

//equal operator
ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	name = copy.name;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name;
		std::cout << " attacks " << target;
		std::cout << " causing " << attackDamage;
		std::cout << " points of damage. ";
		std::cout << "ClapTrap " << name << " has ";
		std::cout << energyPoints << " energiPoints remainig\n";
	}
	else
		std::cout << "Not enought energy points\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name;
		std::cout << " is already dead\n";
		return ;
	}
	hitPoints -= amount;
	std::cout << "ClapTrap " << name;
	std::cout << " recieve " << amount << " of damage. ";
	if ((hitPoints) <= 0)
		std::cout << "ClapTrap " << name << " is dead\n";
	else
	{
		std::cout << "ClapTrap " << name << " has ";
		std::cout << hitPoints << " healh points\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name;
		std::cout << " is repaired for " << amount;
		std::cout << " points of health. Now has ";
		std::cout << hitPoints + amount << " health points. ";
		std::cout << "ClapTrap " << name << " has ";
		std::cout << energyPoints << " energyPoints remainig\n";
		hitPoints += amount;
	}
	else
		std::cout << "Not enought energy points\n";
}
