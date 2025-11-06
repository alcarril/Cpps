

#include "File.hpp"
#include "FileManager.hpp"

//se podria haver usado la calse file en vez de con staticas con un file targert
//y unmetodo que abra el file y elija las flagas, despues componer la clase Filemanger o 
//filter file conel puntero a la clase File o con el file directamente si no querremos poseerlo
//el problema de no poseeerlo es que para manipuarlo valoa a tene que usar metodos de otra clase
//que no sol const asi que el objeto file nunca va a poder estar apuntado por un puntero tipo cosnt.
int main(int argc, char **argv)
{
	std::fstream	*filePtr;
	FileManager		Manager;
	if (argc != 4)
	{
		std::cerr << "Error arguments\n";
		return (1);
	}
	filePtr = File::openFileR(argv[1]);
	if (filePtr == NULL)
		return (1);
	Manager.selectInFile(*filePtr);
	if (!Manager.createOutFile("/tmp/hola"))
	{
		File::closeFile(filePtr);
		return (1);
	}
	if (!Manager.createOutFile("/tmp/hola"))
	{
		File::closeFile(filePtr);
		return (1);
	}
	Manager.filterFile(argv[2], argv[3]);
	// Manager.showFile(*filePtr);
	Manager.showFile(Manager.outFile);
	File::closeFile(filePtr);
	Manager.outFile.close();
	return (0);
}