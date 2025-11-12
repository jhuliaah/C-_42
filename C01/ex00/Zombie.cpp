
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std:cout << "A new body arises from the dead, " << _name << "is reborn a Zombie" << std:: endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << _name << "has been destroyed!" << std:: endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
}