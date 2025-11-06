
#include "ex01.hpp"

std::string	get_firstname(void)
{
	std::string first_name;
	int control = 0;

	while (first_name.empty())
	{
		if (control > 0 )
			std::cout << "First Name cannot be empty. Please enter again." << std::endl;
		std::cout << "First Name: ";
		if (!std::getline(std::cin, first_name))
			return ("");
		first_name = filter_ascii(first_name);
		control++;
	}
	return (first_name);
}


std::string	get_lastname(void)
{
	std::string last_name;
	int control = 0;

	while (last_name.empty())
	{
		if (control > 0 )
			std::cout << "Last Name cannot be empty. Please enter again." << std::endl;
		std::cout << "Last Name: ";
		if (!std::getline(std::cin, last_name))
			return ("");
		last_name = filter_ascii(last_name);
		control++;
	}
	return (last_name);
}

std::string	get_nickname(void)
{
	std::string nick_name;
	int control = 0;

	while (nick_name.empty())
	{
		if (control > 0 )
			std::cout << "Nick Name cannot be empty. Please enter again." << std::endl;
		std::cout << "Nick Name: ";
		if (!std::getline(std::cin, nick_name))
			return ("");
		nick_name = filter_ascii(nick_name);
		control++;
	}
	return (nick_name);
}

std::string	get_secret(void)
{
	std::string secret;
	int control = 0;

	while (secret.empty())
	{
		if (control > 0 )
			std::cout << "Darkest Secret cannot be empty. Please enter again." << std::endl;
		std::cout << "Secret: ";
		if (!std::getline(std::cin, secret))
			return ("");
		secret = filter_ascii(secret);
		control++;
	}
	return (secret);
}

std::string	get_index(void)
{
	std::string index;
	int control = 0;

	while (index.empty())
	{
		std::cout << "Index: ";
		if(!std::getline(std::cin, index))
			return ("");
		control++;
	}
	return (index);
}

bool	get_newcontac(PhoneBook& Phone)
{
	std::string	firstname, lastname, nickname, secret;

	firstname = get_firstname();
	if (firstname.empty())
		return (false);
	lastname = get_lastname();
	if (lastname.empty())
		return (false);
	nickname = get_nickname();
	if (nickname.empty())	
		return (false);
	secret = get_secret();
	if (secret.empty())
		return (false);
	Phone.add_contact(firstname, lastname, nickname, secret);
	return (true);
}

std::string filter_ascii(const std::string& input)
{
	std::string result;
	int i = 0;
	while (input[i] != '\0')
	{
		if (static_cast<unsigned char>(input[i]) < 127)
			result += input[i];
		i++;
	}
	return (result);
}

int PhoneBook::num_contacts = 0;

int	main(void)
{
	PhoneBook	Phone;
	std::string	line;
	
	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			break;
		}
		if (line == "ADD")
		{
			if (get_newcontac(Phone) == false)
			{
				std::cout << std::endl;
				break ;
			}
		}
		else if (line == "SEARCH")
		{
			if (!Phone.display_contact())
			{
				std::cout << std::endl;
				break ;
			}
		}
		else if (line == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}
