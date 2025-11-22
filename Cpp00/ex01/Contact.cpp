
#include "ex01.hpp"
#include "Contact.hpp"

Contact::Contact(const std::string& first_name, const std::string& last_name, 
				const std::string& nick_name, const std::string& phone_number, 
				const std::string& darkest_secret)
				: first_name(first_name), last_name(last_name), 
				nick_name(nick_name), phone_number(phone_number),
				darkest_secret(darkest_secret) {}

Contact::Contact() 
	: first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {}

void	Contact::display_inf(std::string str, size_t inf_len, bool last) const
{
	if (str.size() <= inf_len)
		std::cout << std::right << std::setw(inf_len) << str;
	else
		std::cout << std::right << std::setw(inf_len) << str.substr(0, inf_len - 1) + ".";
	if (last)
		std::cout << " | ";
}

void Contact::dspl_row(void) const
{
	display_inf(this->first_name, 10, true);
	display_inf(this->last_name, 10, true);
	display_inf(this->nick_name, 10, false);
	std::cout << std::endl;
}

void Contact::dspl_contact(void) const
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nick Name: " << this->nick_name << std::endl;
	std::cout << "Phone_number: " << this->phone_number << std::endl;
	std::cout << "Dark Secret: " << this->darkest_secret << std::endl;
}
