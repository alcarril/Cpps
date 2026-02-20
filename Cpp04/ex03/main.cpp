#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


//podemos almacenar la mamteria en los almacenes demateria y acceder aella a atraves de 
//de create materia y asignarla en el personale ->simpre con conpias y clone internamente desde create materia
//podemos instanciar nuevas materia directamete en el personaje y asignarlas
//equipandolas desde el personaje
int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());//extra materia to test full slots
	src->learnMateria(new Ice());//extra materia to test full slots
	src->learnMateria(new Cure());//extra materia to test full slots

	MateriaSource copyMateriaSource;//
	copyMateriaSource = *(static_cast<MateriaSource*>(src));//test asignacion deep copy
	MateriaSource copyMateriaSource2(*static_cast<MateriaSource*>(src));//test	 copy constructor deep copy

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");//test de materia no existente
	me->equip(tmp);//
	tmp = src->createMateria("ice");//
	me->equip(tmp);//

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);//
	me->use(-1, *bob);//

	ICharacter* copyBob = bob;//solo hay que liberar uno
	AMateria* tmp1;//
	tmp1 = src->createMateria("ice");
	copyBob->equip(tmp1);//test deep copy
	copyBob->unequip(0);//test unequip
	delete tmp1;//

	Character juan("juan");
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	juan.equip(tmp2);
	juan.use(0, *me);
	Character copyJuan;
	copyJuan = juan;//test deep copy
	Character copyJuan2(juan);//test deep copy constructor
	// juan.unequip(0);//test unequip
	// delete tmp2;//


	delete bob;
	delete me;
	delete src;
	return 0;
}