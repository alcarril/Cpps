

#include "File.hpp"

//abren el archivo reservando memoria para el y devulven e punterooal objeto generado
std::fstream *File::openFileR(const std::string& name)
{
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::in);
	if (!readFile->is_open())
	{
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

std::fstream *File::openFileW(const std::string& name)
{
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::out);
	if (!readFile->is_open())
	{
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

std::fstream *File::openFileRW(const std::string& name)
{
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::in | std::ios::out);
	if (!readFile->is_open())
	{
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

void File::closeFile(std::fstream *fileObj)
{
	fileObj->close();
	delete fileObj;
}