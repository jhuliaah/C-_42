#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Miguelito");
	ClapTrap b("Joselito");
	
	a.setAttackDamage(5);
	b.setAttackDamage(3);
	
	std::cout << std::endl << "=== Round 1 ===" << std::endl;
	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	b.attack("Miguelito");
	a.takeDamage(b.getAttackDamage());

	std::cout << RED << std::endl << "=== Round 2 ===" << std::endl;
	b.beRepaired(2);

	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	std::cout << RED << std::endl << "=== Final Round ===" << std::endl;
	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	b.attack("Miguelito");
	a.takeDamage(b.getAttackDamage());

	a.announceBattleResult(b);

	std::cout << std::endl;
	return 0;
}