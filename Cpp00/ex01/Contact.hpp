
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact();
		Contact(const std::string& first_name, const std::string& last_name, 
				const std::string& nick_name, const std::string& phone_number, 
				const std::string& darkest_secret);
		void display_inf(std::string str, size_t inf_len, bool last) const;
		void dspl_row(void) const;
		void dspl_contact(void) const ;
};

#endif