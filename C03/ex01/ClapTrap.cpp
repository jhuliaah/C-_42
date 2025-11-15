
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitpoints(10), _energyPoints(10), _attaclDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name Constructor called for" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
	: _name(src._name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called for" << _name << std::endl;
}

ClapTrap&ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	std::cout << "Copy assignment operator called for" << _name << std::endl;
	return *this;
}

ClapTrap:~ClapTrap()
{
	std::cout << "Destrcutor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "❌ ClapTrap " << _name << " is out of energy or hit points and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "💥 ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints == 0)
	{
		std::cout << "☠️ ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "⚠️  ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beReapired(unsigned int amount)
{
	if(_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "❌ ClapTrap " << _name << " can't repair itself!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "🩹 ClapTrap " << _name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
}

void ClapTrap::announceBattleResult(const ClapTrap& opponent) const
{
	std::cout << "\n==== FINAL SCORE ====" << std::endl;
	std::cout << _name << ": " << _hitPoints << " Hit points, " << _energyPoints << " Energy" << std::endl;
	std::cout << opponent._name << ": " << opponent._hitPoints << " Hit points, " << opponent._energyPoints << " Energy" << std::endl;

	std::cout << "\n=== WINNER ===" << std::endl;
	if (_hitPoints > opponent._hitPoints)
		std::cout << _name << " wins the battle!" << std::endl;
	else if (opponent._hitPoints > _hitPoints)
		std::cout << opponent._name << " wins the battle!" << std::endl;
	else
		std::cout << "🤝 It is a tie!" << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}