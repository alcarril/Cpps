

#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>

class File
{
	public:
		static std::fstream *openFileR(const std::string& name);
		static std::fstream *openFileW(const std::string& name);
		static std::fstream *openFileRW(const std::string& name);
		static void closeFile(std::fstream *fileObj);
};

#endif