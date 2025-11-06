


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

#include "Phonebook.hpp"
#include "ex01.hpp"

PhoneBook::PhoneBook() : max_contacts(MAX_CONTACTS)
{
	num_contacts = 0;
}

void PhoneBook::display_header(void) const
{
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nick Name" << " | ";
	std::cout << std::setw(10) << "DarkSecret" << std::endl;
	std::cout << std::string(65, '-') << std::endl;
}

void PhoneBook::add_contact(const std::string& first_name, const std::string& last_name, 
			 const std::string& nick_name, const std::string& darkest_secret)
{
	if (num_contacts < max_contacts)
	{
		Contacts[num_contacts] = Contact(first_name, last_name, nick_name, darkest_secret);
		num_contacts++;
	}
	else
	{
		for (int i = 0; i < num_contacts - 1; i++)
			Contacts[i] = Contacts[i+1];
		Contacts[num_contacts - 1] = Contact(first_name, last_name, nick_name, darkest_secret);
	}
}

bool	PhoneBook::display_contact() const
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
		i = std::atoi(index.c_str());
		if (i < 1 || i > num_contacts)
			std::cerr << "Not a valid index, please try again\n";
		else
			break;
	}
	Contacts[i-1].dspl_contact();
	return (true);
}
