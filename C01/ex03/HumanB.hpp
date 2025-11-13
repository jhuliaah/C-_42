
#ifndef HUMANB_HPP
# define HUMANb_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		HumanB(std::string nameB);
		~HumanB(void);
		void setWeapon(Weapon& weapon);
		void attack(void) const;

	private:
		std::string _nameB;
		Weapon* _weapon;
};

#endif