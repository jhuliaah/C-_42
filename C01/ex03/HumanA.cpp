
#include "HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon& weapon)
:_nameA(nameA), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const
{
	std::cout << _nameA << " attacks with their " << _weapon.getType() << std::endl;
}