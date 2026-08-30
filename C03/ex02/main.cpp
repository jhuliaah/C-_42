
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Miguelito");
	ClapTrap b("Joselito");
	
	a.setAttackDamage(5);
	b.setAttackDamage(3);
	
	std::cout << "=== Round 1 ===" << std::endl;
	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	b.attack("Miguelito");
	a.takeDamage(b.getAttackDamage());

	std::cout << "=== Round 2 ===" << std::endl;
	b.beRepaired(2);

	a.attack("Joselito");
	b.takeDamage(a.getAttackDamage());

	a.announceBattleResult(b);

	std::cout << "=== ScavTrap turn ===" << std::endl;
	ScavTrap sc("Guardian");
	
	sc.attack("intruder");
	sc.takeDamage(30);
	sc.beRepaired(10);
	sc.attack("thief");
	sc.guardGate();

	std::cout << std::endl << "=== FragTrap turn ===" << std::endl;
	FragTrap frag("Terminator");

	frag.attack("bad guy");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << std::endl;
	return 0;
}