
#include "Zombie.hpp"

int	main(void)
{
	int N = 0;
	std::string name;
	const int MAX_ZOMBIES = 1000;

	std::cout << "How many zombies do you want to create? ";
	std::cin >> N;
	std::cin.ignore();

	if (N == 1)
	{
		std::cout << "What is the name of your zombie? " << std::endl;
		std::getline(std::cin, name);
		if (name.empty())
			std::cout << "You didn't gave me a name, so no zombies for you!" << std::endl;
		else
		{
			Zombie* horde = zombieHorde(N, name);
			if (!horde)
			{
				std::cout << "opsie, we couldn't create the zombies" << std::endl;
				return 1;
			}
			horde[0].announce();
			delete[] horde;
		}
	}
	else if (N > 1 && N > MAX_ZOMBIES)
	{
		std::cout << "Why so many Zombies?? do you wanna destroy everything??"
		<< " The Max amount of Zombies is: " << MAX_ZOMBIES << "!!" << std::endl;
	}
	else if(N > 1 && N <= MAX_ZOMBIES)
	{
		std::cout << "What is the name of your zombies? " << std::endl;
		std::getline(std::cin, name);
		if (name.empty()) {
			std::cout << "You didn't gave me a name, so no zombies for you!" << std::endl;
			return 1;
		}
		Zombie* horde = zombieHorde(N, name);
		if (!horde)
		{
			std::cout << "opsie, we couldn't create the zombies" << std::endl;
			return 1;
		}
		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	else
	{
		std::cout << "Invalid prompt, your imbecile!" << std::endl;
		return 1;
	}
	return (0);
}