
#include "easyfind.hpp"

int main(void) {
	//Usar vectores//
	std::cout << "PRUEBAS DE VECTORES\n\n";
	std::vector<int> v1; //Constructor por defecto de vectores, vacio hasta que se añadan valores
	std::cout << "El tamaño del primer vector es contruido por defecto es: " << v1.size() << std::endl;
	std::vector<std::string> vStrings(5); //Constructor parametrizado, espacio para 5 strings vacios
	std::cout << "La longitud del primer string cunado esta vacio es: "<< vStrings[0].length() << std::endl; //imprime 0
	std::cout << "El tamaño del vector recien construido es: " << vStrings.size() << std::endl; //imprime el numero de huecos creados usables es 5
	std::cout << "La capacidad del vector recien construido es: "<< vStrings.capacity() << std::endl; //imprime el numero de huecos creados usables es 5
	vStrings[4] = "El primero de los ultimos";
	std::cout << "El valor de la ultima poscion es: " << vStrings[4] << std::endl; //impimer el primero de los ultimos
	std::cout << "Valor de la ultima posicion expresada con iterador" << *(vStrings.end() - 1) << std::endl; //imrime pepe usando el iterador desreferenciado
	vStrings.push_back("hola");//crea una nueva posicion y añade el valor
	std::cout << "El tamaño del vector despues de hacer un push: " << vStrings.size() << std::endl; //imprime el numero de huecos creados usables ahora es 6 
	std::cout << "El valor de la ultima posicion despues del push: " << vStrings[5] << std::endl;//imprime hola
	vStrings.push_back("pepe");//crea un nueva posisicon y añade una nueva
	std::cout << "El tamño del vector despues de push es: " << vStrings.size() << std::endl; //imprime el numero de huecos creados usables ahora es 7 
	std::cout << "El valor dela ultima posisicon expresada desde el indice es: " << vStrings[6] << std::endl; //imprimer pepe
	std::cout << "El valor dela ultima posicion extresada desde el iterador es: " << *(vStrings.end() - 1) << std::endl; //imrime pepe usando el iterador desreferenciado
	vStrings.insert(vStrings.end() - 1, "Nuevo ultimo valor"); //Al insertar un valor en una posicion no lo susutituimos, creamos una nueva posicion añadimos valor pero en medio
	std::cout << "Despues de insertar el valor donde estaba la ultima posicion el tamaño es: " << vStrings.size() << std::endl;
	std::cout << "El nuevo valor en al posisicon que insertamos es: " << vStrings[6] << std::endl;
	std::cout << "El nuevo ultimo valor desdepues de insertar es: " << vStrings[7] << std::endl;
	try {
		vStrings.at(9); //prueba de acceso invalido deberia saltar ecepccio
	} catch (std::exception &e) {
		std::cerr << "Salta la excepcion: \n";
		std::cerr << e.what() << std::endl;
	}
	for (std::vector<std::string>::iterator it = vStrings.begin(); it < vStrings.end(); it++) { //Recorrer conedor dadno valores
		*it = "new";
	}
	std::cout << "Nuevos valores despues de recorrer dandolos\n";
	int i = 0;
	for (std::vector<std::string>::iterator it = vStrings.begin(); it < vStrings.end(); it++) {
		std::cout << "El nuevo valor de la posicion " << i << " es: " << *it << std::endl;
		i++;
	}
	std::cout << "Crear un contnedor con valores por defecto\n";
	std::vector<int> vComplete(6,3); //Constructor de vector parametrizado con valores por defecto;
	std::cout << "El tmaño del nuevo contenedor es: " << vComplete.size() << std::endl; //Imprime 6
	int j = 0;
	for (std::vector<int>::iterator it = vComplete.begin(); it < vComplete.end(); it++) { //Impimir los valores del constendor "3"
		std::cout << "El valor de la posicion " << i << " es " << *it << std::endl;
		j++;
	}
	std::vector<int> v3(2); //Constrcutor por parametrizado con valores vacios
	std::fill(v3.begin(), v3.end(), 9999); //relenar todos los valores del vector con "9999" -> algoritmo
	std::cout << "El valor del primer valor del contenedor es: " << v3[0] << std::endl;
	std::cout << "El valor del primer valor del contenedor es: " << v3[1] << std::endl;
	std::cout << "El tamaño del vector antes de  limpiarlo es: " << v3.size() << std::endl;
	v3.pop_back(); //Borra la ultima posiccion de memoria
	std::cout << "El tamaño del vector despues de  hacer pop es: " << v3.size() << std::endl;
	v3.clear(); //Borra losvalores y las posiciones de memoria es decri camvia el vector
	std::cout << "El tamaño del vector despues de  limpiarlo es: " << v3.size() << std::endl;

	std::vector<int> v3Copy(v3); //Constrcutor de vector por copia
	std::cout << "El tamaño del vector copiado es: " << v3Copy.size() << std::endl; //imprime el mismo tamaño que el original
	std::vector<int> v3Copytrim(v3.begin(), v3.begin() + 1); //Constrcutor por copia de de solo un rango de valores
	std::cout << "El tamaño del vector copiado con rango es: " << v3Copytrim.size() << std::endl; //imprime el numero de valores copiados
	

	//Pruebas de deques (Funcionan igual que los vectores pero se puede añadir y borrar elementos al porpcipio)
	std::cout << "\n\nPRUEBAS DE DEQUES (Colas dobles) \n\n";
	std::deque<int> deq(3);
	std::cout << "El tamaño de la cola doble es: " << deq.size() << std::endl; //Imprime 3;
	deq[0] = 3;
	deq[1] = 2;
	deq[2] = 1;
	std::cout << "El valor de la primera posicion es: " << deq[0] << std::endl;
	deq.push_front(4); //Añade un posicion al principio con este valor (cambia el tamaño)
	std::cout << "El nuevo tamaño del deque despues del push_front es: " << deq.size() << std::endl;
	std::cout << "El valor de la nueva primera posicion es: " << deq[0] << std::endl;
	std::cout << "El valor de la nueva primera posicion con iterador es: " << *(deq.begin()) << std::endl;
	deq.pop_front(); //Borra la primer posicion y cambia el tamaño
	std::cout << "El nuevo tamaño del deque despues del pop_front es: " << deq.size() << std::endl;
	std::cout << "El valor de la  primera posicion depues del pop_front es: " << deq[0] << std::endl;
	std::cout << "El valor de la  primera posicion despues del pop_front con iterador es: " << *(deq.begin()) << std::endl;


	//Pruebas de listas (Son como las deques, con listas enlazad y no tienen acceso por indeices)
	std::cout << "\n\nPRUEBAS DE LISTAS\n\n";
	std::list<int> list(3); //Constructor por parametrizado con valores vacios
	std::cout << "El tamaño de la lista es: " << list.size() << std::endl; //Imprime 3
	std::generate(list.begin(), list.end(), std::rand); //Rellena la lista con numeros aleatorios ->añgpritmo
	std::cout << "Los valores de la lista son: \n";
	i = 0;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) { //Imprime los valores de la lista
		std::cout << "El valor de la posicion " << i << " es: " << *it << std::endl;
		i++;
	}
	list.sort(); //Ordena la lista
	i = 0;
	std::cout << "Los valores de la lista despues de ordenarla son: \n";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) { //Imprime los valores de la lista
		std::cout << "El valor de la posicion " << i << " es: " << *it << std::endl;
		i++;
	}
	list.reverse(); //Invierte el orden de la lista
	i = 0;
	std::cout << "Los valores de la lista despues de invertir el orden son: \n";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) { //Imprime los valores de la lista
		std::cout << "El valor de la posicion " << i << " es: " << *it << std::endl;
		i++;
	}

	//Pruebads de maps (Contenedores asociativos, almacenan pares de clave-valor, no tienen acceso por indices)
	std::cout << "\n\nPRUEBAS DE MAPS\n\n";
	std::map<std::string, std::string> dicNameConutry; //Constrcutor por defecto N
	std::cout << "El tamaño del diccionario es: " << dicNameConutry.size() << std::endl;
	dicNameConutry["juan"] = "españa"; //Crear nuevos elementos del map
	dicNameConutry["john"] = "usa"; //Crear nuevos elementos del map
	std::cout << "El tamaño del diccionario despues de añadir es: " << dicNameConutry.size() << std::endl;
	std::cout << "El pais de juan es: " << dicNameConutry["juan"] << std::endl; //Imprime la el valor asociado a la clave "juan"
	std::cout << "El pais de john es: " << dicNameConutry["john"] << std::endl; //IMprime el valor asociado a la clave "john"
	std::cout << "El pais de dasdsadsa es: " << dicNameConutry["dsadas"] << std::endl; //No lo encuentra y lo crea con valor vacio
	std::map<std::string, std::string>::iterator it1 = dicNameConutry.begin(); //Crea un iterador al principio del map
	std::cout << "El valor de la primera clave es: " << it1->first << "con valor: " << it1->second << std::endl; //Imprime la primera clave y su valor asociado
	std::cout << "El valor de la primera clave con iterador desreferenciado es: " << (*it1).first << "con valor: " << (*it1).second << std::endl; //Imprime la primera clave y su valor asociado usando el iterador desreferenciado
	std::cout << "El valor del segundo clave es: " << (++it1)->first << "con valor: " << (++it1)->second << std::endl; //Imprime la segunda clave y su valor asociado
	for (std::map<std::string, std::string>::iterator it2 = dicNameConutry.begin(); it2 != dicNameConutry.end(); it2++) { //Recorrer el map imprimiendo las claves y sus valores asociados
		std::cout << "La clave es: " << it2->first << " con valor: " << it2->second << std::endl;
	}
	std::map<std::string, std::string>::iterator it3 = dicNameConutry.find("juan"); //Busca la clave "juan" y devuelve un iterador a esa posicion
	if (it3 != dicNameConutry.end()) { //Si el iterador no es igual al final del map, es decir, si se ha encontrado la clave
		std::cout << "La clave juan se encuentra en el diccionario con valor: " << it3->second << std::endl; //Imprime el valor asociado a la clave "juan"
	}
	else {
		std::cout << "La clave juan no se encuentra en el diccionario\n";
	}
	
	std::map<int, std::string> posPlayers;
	posPlayers[0] = "fede"; //crear nuevos elementos del map con clave entera y valor string
	posPlayers[1] = "fer"; //crear nuevos elementos del map con clave entera y valor string
	posPlayers[2] = "paco"; //crear nuevos elementos del map con clave entera y valor string
	posPlayers[3] = "Alex"; //crear nuevos elementos del map con clave entera y valor string
	posPlayers.insert(std::pair<int, std::string>(4, "lucas")); //Insertar nuevos elementos usando pairs
	std::map<int, std::string>::iterator lower = posPlayers.lower_bound(2);//Nos da el iterador a la primera posicion que es igual o mayor que el valor dado, en este caso 2
	std::cout << "El intergrante del diccionario menor que 2 es: " << lower->second << std::endl; //impirme paco
	std::map<int, std::string>::iterator upper = posPlayers.upper_bound(2); //Nos da el iterador a la primera posicion que es mayor que el valor dado, en este caso 2
	std::cout << "El intergrante del diccionario mayor que 2 es: " << upper->second << std::endl; //imprime Alex

	std::map<int, std::string> copyMap(posPlayers); //Constructor por copia de map
	std::cout << "El tamaño del map copiado es: " << copyMap.size() << std::endl; //imprime el mismo tamaño que el original
	for (std::map<int, std::string>::iterator it = copyMap.begin(); it != copyMap.end(); it++) { //La consicion del iterador tiene que ser != porque es un arbol y no son secuenciales
		std::cout << "La clave es: " << it->first << " con valor: " << it->second << std::endl;
	}


	//Pruebas de sets (Contenedores asociativos, almacenan valores unicos, no tienen acceso por indices)
	std::cout << "\n\nPRUEBAS DE SETS\n\n";
	std::set<int> setInt; //Constructor por defecto
	std::cout << "El tamaño del set es: " << setInt.size() << std::endl; //imprime 0
	setInt.insert(1); //metdo para insertar un nuevo valor en el set
	setInt.insert(44); //metdo para insertar un nuevo valor en el set
	setInt.insert(-6575676); //metdo para insertar un nuevo valor en el set
	setInt.insert(-6575676); // no se añade el valor repetido
	std::cout << "El tamaño del set despues de insertar valores es: " << setInt.size() << std::endl; //imprime 3, no se añadio el valor repetido

	std::set<int>::iterator itSet = setInt.find(44); //Busca el valor 44 y devuelve un iterador a esa posicion
	if (itSet != setInt.end()) { //Si el iterador no es igual al final del set, es decir, si se ha encontrado el valor
		std::cout << "El valor 44 se encuentra en el set\n";
	}
	else {
		std::cout << "El valor 44 no se encuentra en el set\n";
	}

	std::set<int> copySet(setInt); //Constrcutor por copia de los sets
	for (std::set<int>::iterator itSet = copySet.begin(); itSet != copySet.end(); itSet++) { //La consicion del iterador tiene que ser != porque es un arbol y no son secuenciales

	}


	//Pruebas de contenedores asociativos(solo permiten accesos por metodos internos del objeto)//
	//Pruebas de stacks (pilas, se crean sobre vectores o deques)//
	std::cout << "\n\n PRUEBAS DE PILAS\n\n";
	std::stack<int> st; // Constructor por defecto pila vacia
	std::cout << "El tamño de la pila es: "  << st.size() << std::endl;//Imprime 0
	bool empty = st.empty(); //devuleve 1 si esta vacia y 0 si no lo esta
	std::cout << "Comprobacion de pila vacia " << empty << std::endl; //Devuleve 1 porque esta vacia
	st.push(3); //añade un elemeno en memoria con este valor
	std::cout << "El tamño de la pila despues de añadir es: "  << st.size() << std::endl; //imprime 1
	std::cout << "El valor primer valor de la pila es: " << st.top() << std::endl; // Imprime el 3 (numero)
	st.push(4); //añade un elemeno en memoria con este valor
	std::cout << "El tamño de la pila despues de añadir es: "  << st.size() << std::endl; //imprime 2
	std::cout << "El valor primer valor de la pila despues de añadir es: " << st.top() << std::endl; // Imprime el 4 (numero)
	st.pop(); //elimina el elemento de arriba de la pila
	std::cout << "El tamño de la pila despues de hacer pop es: " << st.size() << std::endl; //imprime 1
	std::cout << "El valor primer valor de la pila depues de pop vuelve a ser: " << st.top() << std::endl; // Imprime el 3 (numero)


	std::vector<int> vector;//creo vector
	vector.push_back(1); //añado un elemnto nuevo
	vector.push_back(2); //añado un elemnto nuevo
	vector.push_back(3); //añado un elemnto nuevo
	for (std::vector<int>::iterator it8 = vector.begin(); it8 != vector.end(); ++it8) { //Recorrer conedor dadno valores
		std::cout << "El valor de la posicion es: " << *it8 << std::endl;
	}
	
	std::stack<int, std::vector<int> > stackVector(vector); //Construccion por emascaracion (copia) de otro contendor con las deques funciona igual
	std::cout << "El primer valor del stackvector construido porcopia es: " << stackVector.top() << std::endl;
	stackVector.push(4); //Añado un elemnto nuevo
	std::cout << "El primer valor del stackvector despues del push es: " << stackVector.top() << std::endl;
	std::cout << "Comprobacion si al añadir un elento nuevo esta en la memoria del vector original: " << *(vector.end() - 1) << std::endl; //impimre 3 porque se construye por copia.
	
	//Pruebas de queues(se crean sobre deques)//
	std::cout << "\n\nPRUEBAS DE COLAS\n\n";
	std::queue<int> q; //Constructor por defecto, cola vacia
	std::cout << "El tamaño de la cola es: " << q.size() << std::endl; //imprime 0
	bool emptyQ = q.empty(); //devuleve 1 si esta vacia y 0 si no lo esta
	std::cout << "Comprobacion de cola vacia " << emptyQ << std::endl; //Devuleve 1 porque esta vacia
	q.push(3); //añade un elemeno en memoria
	std::cout << "El tamño de la cola despues de añadir es: "  << q.size() << std::endl; //imprime 1
	std::cout << "El valor primer valor de la cola es: " << q.front() << std::endl; // Imprime el 3 (numero)
	std::cout << "El valor del ultimo valor de la cola es: " << q.back() << std::endl; // Imprime el 3 (numero)
	q.push(4); //añade un elemeno en memoria
	std::cout << "El tamño de la cola despues de añadir es: "  << q.size() << std::endl; //imprime 2
	std::cout << "El valor primer valor de la cola despues de añadir es: " << q.front() << std::endl; // Imprime el 3 (numero)
	std::cout << "El valor del ultimo valor de la cola despues de añadir es: " << q.back() << std::endl; // Imprime el 4 (numero)
	q.pop(); //elimina el elemento de arriba de la pila
	std::cout << "El tamño de la cola despues de hacer pop es: " << q.size() << std::endl; //imprime 1
	std::cout << "El valor primer valor de la cola depues de pop vuelve a ser: " << q.front() << std::endl; // Imprime el 4 (numero)
	std::cout << "El valor del ultimo valor de la cola depues de pop vuelve a ser: " << q.back() << std::endl; // Imprime el 4 (numero)

	//Pruebas de PriorityQueues (es un heap (arbol) binario sobre un vector)//
	std::cout << "\n\nPRUEBAS DE COLAS DE PRIORIDAD\n\n";
	std::priority_queue<int> pq; //Constructor por defecto, cola de prioridad vacia
	std::cout << "El tamaño de la cola de prioridad es: " << pq.size() << std::endl; //imprime 0
	bool emptyPQ = pq.empty(); //devuleve 1 si esta vacia y 0 si no lo esta
	std::cout << "Comprobacion de cola de prioridad vacia " << emptyPQ << std::endl; //Devuleve 1 porque esta vacia
	pq.push(3); //añade un elemeno en memoria
	std::cout << "El tamño de la cola de prioridad despues de añadir es: "  << pq.size() << std::endl; //imprime 1
	std::cout << "El valor primer valor de la cola de prioridad es: " << pq.top() << std::endl; // Imprime el 3 (numero)
	pq.push(4); //añade un elemeno en memoria
	std::cout << "El tamño de la cola de prioridad despues de añadir es: "  << pq.size() << std::endl; //imprime 2
	std::cout << "El valor primer valor de la cola de prioridad despues de añadir es: " << pq.top() << std::endl; // Imprime el 4 (numero)
	pq.push(2); //añade un elemeno en memoria
	std::cout << "El tamño de la cola de prioridad despues de añadir es: "  << pq.size() << std::endl; //imprime 3
	std::cout << "El valor primer valor de la cola de prioridad despues de añadir es: " << pq.top() << std::endl; // Imprime el 4 (numero)
	pq.pop(); //elimina el elemento de arriba de la pila
	std::cout << "El tamño de la cola de prioridad despues de hacer pop es: " << pq.size() << std::endl; //imprime 2
	std::cout << "El valor primer valor de la cola de prioridad depues de pop vuelve a ser: " << pq.top() << std::endl; // Imprime el 3 (numero)
	
	//Ejerccios de Cpp08/ex00//
	std::cout << "\n\nPRUEBAS DE LA FUNCION EASYFIND\n\n";
	//Con vector
	std::vector<int> vec1(5);
	std::generate(vec1.begin(), vec1.end(), std::rand);
	vec1[3] = 465546;
	try {
		std::vector<int>::const_iterator vecIt = easyFind(vec1, 465546); //Si campbio el valor puede que no este
		std::cout << "El valor de vecIt es: " << *vecIt << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl; 
	}
	

	//Con deque -> Por hacer pero mismo funcionamiento

	std::deque<int> deq12(5);
	deq12.push_back(3);
	deq12.push_front(4);
	deq12.push_back(5);
	try {
		std::deque<int>::const_iterator deqiter = easyFind(deq12, 3);
		std::cout << "Elemento encontrado en deque: " << *deqiter << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//Con list -> por hacer pero mismo funcionamiento
	std::list<int> list12(5);
	list12.push_back(3);
	list12.push_front(4);
	try {
		std::list<int>::const_iterator listiter = easyFind(list12, 4);
		std::cout << "Elemento encontrado en list: " << *listiter << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//El resto no se pueden porque no se contemplan en el enunciado o no tienen iteradores

}
