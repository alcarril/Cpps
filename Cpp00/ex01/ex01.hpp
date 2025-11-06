

#ifndef EX01_HPP
#define EX01_HPP

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

std::string	get_firstname(void);
std::string	get_lastname(void);
std::string	get_nickname(void);
std::string	get_secret(void);
std::string	get_index(void);
bool		get_newcontac(PhoneBook& Phone);
std::string filter_ascii(const std::string& input);

#endif