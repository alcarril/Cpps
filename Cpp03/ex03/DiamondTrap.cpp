#include "DiamondTrap.hpp"

//hay que añadir this?
//hay que poner todos los constrcutores de las clases base en la inicializacion?
DiamondTrap::DiamondTrap() : ClapTrap() {
	this->hitPoints = FragTrap::hitPoints; // Usar los valores de FlagTrap
	this->energyPoints = ScavTrap::energyPoints; // Usar los valores de ScavTrap
	this->attackDamage = FragTrap::attackDamage; // Usar los valores de FlagTrap
	this->name = "Default DiamondTrap"; // Nombre específico de DiamondTrap
	std::cout << "DiamondTrap " << name << " created with default values\n";
	std::cout << "The diamond goat " << this->name << " appear in the arena !" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << this->hitPoints << std::endl; 
	std::cout << std::setw(27) << "Energy Points : " << this->energyPoints << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << this->attackDamage << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& _name)
: ClapTrap(_name + "_clap_name")  {
	this->hitPoints = FragTrap::hitPoints; // Usar los valores de FlagTrap
	this->energyPoints = ScavTrap::energyPoints; // Usar los valores de ScavTrap
	this->attackDamage = FragTrap::attackDamage; // Usar los valores de FlagTrap
	this->name = _name; // Nombre específico de DiamondTrap
	std::cout << "DiamondTrap " << name << " creado con valores combinados\n";
	std::cout << "The diamond goat " << this->name << " appear in the arena !" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << this->hitPoints << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << this->energyPoints << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << this->attackDamage << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
: ClapTrap(copy), ScavTrap(copy), FragTrap(copy) { // Inicializa todas las clases base
	name = copy.name; // Copia el atributo específico de DiamondTrap
	std::cout << "DiamondTrap " << name << " creado por copia\n";
	std::cout << "The diamond goat " << this->name << " appear in the arena !" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << this->hitPoints << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << this->energyPoints << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << this->attackDamage << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy) {
	if (this != &copy) {
		hitPoints = copy.hitPoints;
		energyPoints = copy.energyPoints;
		attackDamage = copy.attackDamage;
		name = copy.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destroyed\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << "\n";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
