

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void	clapTrapLookUp( ClapTrap& test) {
	test.attack("test Clap");
}

// void	ScavTrapLookUp( ScavTrap& test) {
// 	test.attack("test Slav");
// 	// test.guardGate();
// }

int main(void)
{
	// ClapTrap	alf("alf");
	// ClapTrap	jordi(ClapTrap("jordi"));
	// ClapTrap	fakejordi(jordi);

	// std::cout << std::endl;
	// alf.attack("your mother");
	// jordi.attack("your grandmother");
	// fakejordi.attack("your cousin");

	// std::cout << std::endl;
	// int i = 0;
	// while (i++ < 10)
	// 	alf.takeDamage(1);
	// alf.takeDamage(5);

	// std::cout << std::endl;
	// jordi.takeDamage(5);
	// jordi.beRepaired(5);
	// jordi.takeDamage(11);
	// jordi.takeDamage(1);
	// std::cout << std::endl;

	// std::cout << "FlagTrap test////////////////////////////\n\n\n";
	// FlagTrap subBaseC("Flagtrap");
	// subBaseC.attack("marvin");
	// subBaseC.beRepaired(40);
	// subBaseC.takeDamage(90);
	// subBaseC = FlagTrap("lolo");
	// subBaseC.attack("marvin");

	// std::cout << "SlavTrap test////////////////////////////\n\n\n";

	// ////////////////////test de constructor por copia
	// std::cout << "[Test de construtor por copia]\n";
	// ClapTrap	baseA("AA");
	// ScavTrap	subBaseA("BB");
	// // ScavTrap 	jhony(baseA);//No deja construir porque ClapTrap no es SlavTrap
	// ClapTrap 	mak(subBaseA);//Deja construir porque ScavTrap es tambien ClapTrap ->object shifting
	// mak.attack("Gadafi");
	// // mak.guard...no es un metodo acced¡sible por 
	// // ScavTrap 	jhony1(ClapTrap("pepe"));//No deja (metofo de seguridada de C++)
	// ClapTrap 	mak1(ScavTrap("pepe"));//Deja asignar
	// mak.attack("a fucking sionist");

	// //////////////test de igualacion
	// std::cout << "[Test de igualacion]\n";
	// ClapTrap	base("be");
	// ScavTrap	subBase("ah");

	// base = subBase; //Los mienbros de base estan en subbase por lo que se puede->object shiftinf no esbuena practica
	// base.attack("the weakest beacause this is the jungle");
	// // subBase = base; //Los mienbros de subase no esta garantizado que esten en base

	// ///////////////test de creacion de obejtos dinamicos//
	// std::cout << "[Test de objetos dinamicos]\n";
	// ClapTrap *basePtr;
	// // ScavTrap *subBasePtr = NULL;

	// basePtr = new ScavTrap("heapScav"); //deja asignar
	// // basePtr->guard...//no incluye este metodo
	// basePtr->attack("alocao");
	// delete basePtr;
	// // subBasePtr = new ClapTrap("heabClap");//no deja asignar

	// ///////////test de polimorfismo en funciones argumentos de funciones que usan
	// ///////////miembro compartido
	// std::cout << "[Test de polimorfismos]\n";
	// ClapTrap baseObj("FuncBase");
	// ScavTrap subBaseObj("FunnSubBase");

	// //deja pasar por el parametro objetos base y subase porque el los metdos y atributos
	// //que se usen en la funcion solo vana a estar incluidos en base asi que seguro que lo
	// //estan en subbase aunque sea con otros valores o comportamientos (polimorfismo)
	// clapTrapLookUp(baseObj);//deberia devolver el attacke de base
	// clapTrapLookUp(subBaseObj);//deberia devolver el atacke de subbase

	// //
	// ScavTrapLookUp(subBaseObj); //deberia devolver el atacke de subbase
	// // ScavTrapLookUp(baseObj);//no se puede por poteccionn

	

	// //////////////tess de creciacion de Slavtrap clase subbase//
	// std::cout << "[Test de creacion de clase sub base]\n";
	// ScavTrap	salf("salf");
	// ScavTrap	sjordi(ScavTrap("sjordi"));
	// ScavTrap	sfakejordi(sjordi);
	// ScavTrap	defaul("default");

	// std::cout << std::endl;
	// salf.attack("your mother");//Fucniona
	// sjordi.attack("your grandmother");//Funciona
	// sfakejordi.attack("your cousin");//Funciona
	// defaul.attack("your dog");//Funciona
	// defaul = salf;//Funciona
	// defaul.attack("your stepmother");//Funciona


	// std::cout << std::endl;
	// int j = 0;
	// while (j++ < 10)
	// 	salf.takeDamage(1);
	// salf.takeDamage(5);

	// std::cout << std::endl;
	// sjordi.takeDamage(5);
	// sjordi.beRepaired(5);
	// sjordi.takeDamage(11);
	// sjordi.takeDamage(1);
	// std::cout << std::endl;

	std::cout << "DiamondTrap test////////////////////////////\n\n\n";
	DiamondTrap	dia("Diamondito");
	DiamondTrap	dia2;
	// dia.attack("the enemy");
	// dia.whoAmI();
	dia2.attack("no one");
	dia2.takeDamage(20);
	dia2.beRepaired(10);
	dia2.whoAmI();
	dia2.highFivesGuys();
	dia2.guardGate();
	return(0);
}
