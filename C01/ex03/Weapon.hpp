
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(void);
		Weapon(const std::string& type);
		~Weapon(void);
		const std::string& getType(void) const;
		void setType(std::string _type);

	private:
		std::string _type;
};

#endif