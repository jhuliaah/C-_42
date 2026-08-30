
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap&FragTrap::operator=(const FragTrap & src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "FragTrap copy assignment operator called for " << _name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "❌ FragTrap " << _name << " is out of energy or hit points and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "💥 FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "🙌 HIGH FIVE!!!" << std::endl;
}