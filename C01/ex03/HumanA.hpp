
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	public:
		HumanA(std::string nameA, Weapon& weapon);
		~HumanA(void);
		void attack(void) const;

	private:
		std::string _nameA;
		Weapon& _weapon;
};

#endif