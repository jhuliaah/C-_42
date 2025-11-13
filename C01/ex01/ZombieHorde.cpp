
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);

		std::cout << "A new body arises from the dead, " << name << " is reborn a Zombie" << std:: endl;
	}
	return horde;
}

