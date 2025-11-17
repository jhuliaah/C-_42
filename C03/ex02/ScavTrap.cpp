
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap&ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "ScavTrap copy assignment operator called for " << _name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "❌ ScavTrap " << _name << " is out of energy or hit points and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "💥 ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "🛡️  ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}