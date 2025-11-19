

#include "File.hpp"

//This functions open a file in different modes and return a pointer to the fstream object
//The c_str is used to convert the string to a const char pointer, because the parameter
//of the fstream constructor is a const char pointer

//This function opens a file in read mode
std::fstream *File::openFileR(const std::string& name) {
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::in);
	if (!readFile->is_open()) {
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

//This function opens a file in write mode
std::fstream *File::openFileW(const std::string& name) {
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::out);
	if (!readFile->is_open()) {
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

//This function opens a file in read and write mode
std::fstream *File::openFileRW(const std::string& name) {
	std::fstream *readFile;

	readFile = new std::fstream(name.c_str(), std::ios::in | std::ios::out);
	if (!readFile->is_open()) {
		delete readFile;
		std::cerr << "Error: file don`t open" << std::endl;
		return (NULL);
	}
	return (readFile);
}

//This function closes the file and deletes the fstream object to free memory
void File::closeFile(std::fstream *fileObj) {
	fileObj->close();
	delete fileObj;
}