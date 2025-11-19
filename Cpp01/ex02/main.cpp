
#include <string>
#include <iostream>

//The  references has the same memory location as the variable that theyp pointed
//the pointers has his own memory location, and they held the memory location of the
/*
	NOTES;
	1.- The references allways refer the same variable, you only can change the
	value of the variable. If you inicialize the reference without givin a value
	the compiler complains
*/
int main(void)
{
	std::string		str;
	std::string*	ptrStr;
	std::string&	refStr = str;//1

	ptrStr = &str;
	//Memory adress of string variable
	std::cout << "The memory adress of str is: " << &str << std::endl;
	//The memory address held by stringPTR
	std::cout << "The memory held by ptrStr is: " << ptrStr << std::endl;
	// The memory address held by stringREF
	std::cout << "The memory held by refStr is: " << &refStr << std::endl;

	str = "HI THIS IS BRAIN";
	// The value of the string variable
	std::cout << "The value of str is: " << str << std::endl;
	// The value pointed to by stringPTR
	std::cout << "The value pointed by ptrStr is: " << *ptrStr << std::endl;
	std::cout << "The value pointed by ptrStr is: " << ptrStr[0] << std::endl;
	// The value pointed to by stringREF
	std::cout << "The value pointed by refStr is: " << refStr << std::endl;
	return (0);
}