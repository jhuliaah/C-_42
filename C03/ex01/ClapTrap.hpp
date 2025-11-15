
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap&operator=(const ClapTrap &src);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setAttackDamage(unsigned int amount);
		unsigned int getAttackDamage() const;

		void announceBattleResult(const ClapTrap& opponent) const;
};

#endif