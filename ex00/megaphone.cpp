#include <iostream>
#include <cctype>
#include <string>

//Using std::cout only
static void ft_toupper_str(char **argv)
{
	for (int j = 1; argv[j] != NULL; j++)
	{
		for (int i = 0; argv[j][i] != '\0'; i++)
			std::cout << static_cast<char>(toupper(argv[j][i]));
	}
	std::cout << std::endl;
}

//Creating a std::string object, with constrcutor an metod to analize de string
static void ft_toupper2_str(char **argv)
{
	for (int j = 1; argv[j] != NULL; j++)
	{
		std::string arg(argv[j]);
		for (size_t i = 0; i < arg.length(); i++) 
			std::cout << static_cast<char>(std::toupper(arg[i]));
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 2)
		ft_toupper_str(argv);
	if (argc > 2)
		ft_toupper2_str(argv);
	return (0);
}
