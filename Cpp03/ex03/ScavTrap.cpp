
#include "ScavTrap.hpp"

//Default constructor: si la clase base tuviese parametros tipo referencia
//o parametros const se tendria que usar un constrcutor parametrizado is queremos
//cambiar los valores deinico enla subbase porque mediante asignacione en el cuerpo
//de la funcion estariamos cambiando su valro despues de inicializarlo. Ademas los 
//atributo de la clase base tienen que estar en protected no e private por el hecho de 
//que en las clases que lo heredan tiene valores diferentes
ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	name = "Default SlavTrap";
	std::cout << "ScavTrap default constructor called\n";
}

//Parameter constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap parameter constructor called\n";
}

//Copy constructor (i can use inicialization list also)
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called\n";
}

//Destructor->prbar si llama al de ClapTrap automaticamente: Si
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " default destructor called\n";
}

//equal operator
ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	name = copy.name;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ScavTrapppp " << name;
		std::cout << " attacks " << target;
		std::cout << " causing " << attackDamage;
		std::cout << " points of damage. ";
		std::cout << "ScavTrapppp " << name << " has ";
		std::cout << energyPoints << " energiPoints remainig\n";
	}
	else
		std::cout << "Not enought energy points\n";
}

//Metodo de la clase subbase SlavTrap
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is on gate keeper mode\n";
}
