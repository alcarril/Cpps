

#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>

//The methons of this class open and close files in different modes
//they are static methods, so you don't need to create an object of the class to use them
class File
{
	public:
		static std::fstream *openFileR(const std::string& name);
		static std::fstream *openFileW(const std::string& name);
		static std::fstream *openFileRW(const std::string& name);
		static void closeFile(std::fstream *fileObj);
};

#endif