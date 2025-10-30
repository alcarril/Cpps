#include <iostream>
#include <iomanip>
#include <string>

//Single resposibility principle applied: Contact class to manage individual contact details
//Data validation and user interaction should be handled elsewhere
//Reusable and maintainable code structure
//Unit tests can be easily created for Contact and PhoneBook classes

// Contact class to represent an individual contact
// Removed const from member variables to allow assignment after construction
// Added constructors for easier initialization

//No uso index porque no es necesario para la funcionalidad basica de PhoneBook
// Si se necesita, se puede agregar un getter para el index
//uso de static para el Phonebook num_contacts para llevar la cuenta de contactos,yya que solo
//va a haber una instancia de Phonebook es decir un objeto Phonebook

//Uso de referencias en los metodos para evitar copias innecesarias, tienen mejor performance
//y ademas tienen que ser constantes para evitar modificaciones accidentales y protege lo parametros
//temporales

//El cnostructor de PHonebook inicializa max_contacts en la lista de inicialización y usa elcontructor
//por defecto de Contact para inicializar el array de contactos, sin constrcutor por defectos de contactos
//no se inicializan correctamente

//contactos tiene un constrcutor con parametros para facilitar la inicialización de nuevos contactos, sino habria que
//modificar los atributos uno por uno y hacerlos publicos o usar setters, lo cual no es recomendable


void	display_inf(std::string str, size_t inf_len, bool last)
{
	if (str.size() <= inf_len)
		std::cout << std::right << std::setw(inf_len) << str;
	else
		std::cout << std::right << std::setw(inf_len) << str.substr(0, inf_len - 1) + ".";
	if (last)
		std::cout << " | ";
}
void display_header(void)
{
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nick Name" << " | ";
	std::cout << std::setw(10) << "DarkSecret" << std::endl;
	std::cout << std::string(65, '-') << std::endl;
}
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

class Contact
{
	private:
		std::string first_name; // Eliminado const
		std::string last_name;  // Eliminado const
		std::string nick_name;  // Eliminado const
		std::string darkest_secret; // Eliminado const

	public:
		Contact() 
			: first_name(""), last_name(""), nick_name(""), darkest_secret("") {}

		Contact(const std::string& first_name, const std::string& last_name, 
				const std::string& nick_name, const std::string& darkest_secret)
			: first_name(first_name), last_name(last_name), 
			  nick_name(nick_name), darkest_secret(darkest_secret) {}
		void dspl_row(void) const
		{
			display_inf(first_name, 10, true);
			display_inf(last_name, 10, true);
			display_inf(nick_name, 10, true);
			display_inf(darkest_secret, 10, false);
			std::cout << std::endl;
		}
		void dspl_contact(void) const
		{
			std::cout << "First Name: " << this->first_name << std::endl;
			std::cout << "Last Name: " << this->last_name << std::endl;
			std::cout << "Nick Name: " << this->nick_name << std::endl;
			std::cout << "Dark Secret: " << this->darkest_secret << std::endl;
		}
};

class PhoneBook 
{
	private:
		const int max_contacts;
		static int num_contacts;
		Contact Contacts[8];
	public:
		PhoneBook() : max_contacts(3)
		{
			num_contacts = 0;
		}
		void add_contact(const std::string& first_name, const std::string& last_name, 
						 const std::string& nick_name, const std::string& darkest_secret)
		{
			int i;
			if (num_contacts < max_contacts)
			{
				Contacts[num_contacts] = Contact(first_name, last_name, nick_name, darkest_secret);
				num_contacts++;
			}
			else
			{
				for (int i = num_contacts - 2; i >= 0; i--)
					Contacts[i + 1] = Contacts[i];
				i = (num_contacts % max_contacts) + 1;
				Contacts[i] = Contact(first_name, last_name, nick_name, darkest_secret);
			}
		}
		bool	display_contact() const
		{
			std::string index;
			int i;

			if (num_contacts == 0)
			{
				std::cerr << "No contacts added, try to add one\n";
				return (true);
			}
			display_header();
			for (int i = 0; i < num_contacts; i++)
			{
				std::cout << std::setw(10) << (i + 1);
				std::cout << " | ";
				Contacts[i].dspl_row();
			}
			while (true)
			{
				index = get_index();
				if (index.empty())
					return (false);
				try
				{
					i = std::stoi(index); // Intentar convertir la entrada a un entero
					if (i < 1 || i > num_contacts)
						std::cerr << "Not a valid index, please try again\n";
					else
						break;
				}
				catch (const std::invalid_argument& e)
				{
					std::cerr << "Invalid input. Please enter a valid number.\n";
				}
				catch (const std::out_of_range& e)
				{
					std::cerr << "Number out of range. Please enter a valid index.\n";
				}
			}
			Contacts[i-1].dspl_contact();
			return (true);
		}
};

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
