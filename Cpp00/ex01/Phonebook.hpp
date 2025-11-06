
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>

#define MAX_CONTACTS 8

class PhoneBook 
{
	private:
		const int max_contacts;
		static int num_contacts;
		Contact Contacts[MAX_CONTACTS];
	public:
		PhoneBook();
		void	add_contact(const std::string& first_name, const std::string& last_name, 
						 const std::string& nick_name, const std::string& darkest_secret);
		void	display_header(void) const;
		bool	display_contact() const;
};

#endif