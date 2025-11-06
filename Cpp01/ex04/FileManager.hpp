

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>

class FileManager
{
	private:
		std::fstream	*inFile;
	public:
		std::fstream	outFile;
		FileManager();
		FileManager(std::fstream& imputFile);
		void selectInFile(std::fstream& imputFile);
		bool createOutFile(const std::string &name);
		void showFile(std::fstream& file);
		void filterFile(const std::string& s1, const std::string& s2);
};

#endif 