
#include "megaphone.hpp"

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < strlen(argv[i]); j++)
			argv[i][j] = toupper((unsigned char)argv[i][j]);
	}
	for (int i = 1; i < argc; i++)
		std::cout << (argv[i]);
		std::cout << "\n";
	return (0);
}
