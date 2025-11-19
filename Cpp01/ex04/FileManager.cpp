#include "FileManager.hpp"
#include "FileManager.hpp"

FileManager::FileManager() : inFile(NULL) {}

FileManager::FileManager(std::fstream& imputFile) 
	: inFile(&imputFile){}

//selects the infile, the class does not own it, it only uses it but
//needs to close it and free memory
void FileManager::selectInFile(std::fstream& inputFile) {
	if (inFile != NULL)
	{
		if (inFile->is_open())
			inFile->close();
		delete inFile;
		inFile = NULL;
	}
	inFile = &inputFile;
}

//creates the outfile, if a file was already open, since the object is not destroyed
//between method calls, it closes it to avoid leaving open file descriptors
bool FileManager::createOutFile(const std::string &name) {
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

//reads the file line by line, then resets the eof flags and sets the file descriptor offset
//to the initial position. Uses the iostream library to handle file descriptors
void FileManager::showFile(std::fstream& file) {
	std::string line;

	while (std::getline(file, line))
		std::cout << line << std::endl;
	file.clear();
	file.seekg(0, std::ios::beg);
}

//this function acts like variable interpolation in environment variables but you don't have to
//explicitly manage memory like in C
void FileManager::filterFile(const std::string& s1, const std::string& s2) {
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
					j++;
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
