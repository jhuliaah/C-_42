
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Miguelito");
	ClapTrap b("Joselito");
	
	a.setAttackDamage(5);
	b.setAttackDamage(3);
	
	std::cout << RED << std::endl << "=== Round 1 ===" << RESET << std::endl;
	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	b.attack("Miguelito");
	a.takeDamage(b.getAttackDamage());

	std::cout << RED << std::endl << "=== Round 2 ===" << RESET << std::endl;
	b.beRepaired(2);

	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	a.announceBattleResult(b);

	std::cout << YELLOW << std::endl << "=== ScavTrap turn ===" << RESET << std::endl;
	ScavTrap sc("Guardian");
	
	sc.attack("intruder");
	sc.takeDamage(30);
	sc.beRepaired(10);
	sc.attack("thief");
	sc.guardGate();

	std::cout << std::endl;
	return 0;
}