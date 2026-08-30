
#include "Zombie.hpp"

int main(void)
{
	Zombie* z1 = newZombie("the cadaver bride");
	z1->announce();
	delete z1;

	randomChump("Victor");
	return(0);
}
