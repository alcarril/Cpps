

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>

//this class can be imporved changin the arquitecture to use composition instead of aggregation
//the class FileManager does not own the inFile it only uses it, so the user has to manage
//the memory of the inFile object. Other imporvement can be use this class only to filter
//the file and have a inforle pointer a nd a outFile pointer and have methods to set them
//and a method to filter from inFile to outFile
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