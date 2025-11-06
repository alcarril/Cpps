#include "FileManager.hpp"
#include "FileManager.hpp"

FileManager::FileManager() : inFile(NULL) {}

FileManager::FileManager(std::fstream& imputFile) 
	: inFile(&imputFile){}

//seleccion el infile, la clase no lo posee solo lo utiliza pero
//necesita cerrarlo y liberar memoria
void FileManager::selectInFile(std::fstream& inputFile)
{
	if (inFile != NULL)
	{
		if (inFile->is_open())
			inFile->close();
		delete inFile;
		inFile = NULL;
	}
	inFile = &inputFile;
}

//crea el outfile si ya habia un file abierto como el objeto no se destruye entre llamada
//y llamada la metodo lo cierra para no dejar fds abiertos
bool FileManager::createOutFile(const std::string &name)
{
	if (outFile.is_open())
		outFile.close();
	outFile.open(name.c_str(), std::ios::out | std::ios::in | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Error: No se pudo crear el archivo de salida: ";
		std::cerr << name << std::endl;
		return (false);
	}
	return (true);
}

//lee el archivo linea a linea despues resetea las flags de eof y pone el offset del fd
//en la posidion inicual libreria  iostream para manejar fds
void FileManager::showFile(std::fstream& file)
{
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	file.clear();
	file.seekg(0, std::ios::beg);
}

//esta funciones aocm ola interpolacion de variables de entorno pero no tienes que manejar 
//la memeoria explicitamente como en C
void FileManager::filterFile(const std::string& s1, const std::string& s2)
{
	std::string line;
	std::string filterLine;
	while (std::getline(*inFile, line))
	{
		filterLine.clear();
		for (size_t i = 0; i < line.size(); i++)
		{
			if (line[i] == s1[0])
			{
				size_t j = 0;
				while (j < s1.size() && i + j < line.size() && line[i + j] == s1[j])
				{
					j++;
				}
				if (j == s1.size())
				{
					filterLine += s2;
					i += s1.size() - 1;
				}
				else
					filterLine += line[i];
			}
			else
				filterLine += line[i];
		}
		outFile << filterLine << std::endl;
	}
	inFile->clear();
	inFile->seekg(0, std::ios::beg);
	outFile.seekg(0, std::ios::beg);
}
