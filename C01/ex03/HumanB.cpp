
#include "HumanB.hpp"

HumanB::HumanB(std::string nameB)
:_nameB(nameB), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (_weapon)
		std::cout << _nameB << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _nameB << " is barehands, let's ruuun!!" << std::endl;
}