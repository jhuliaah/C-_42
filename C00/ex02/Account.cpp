
#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor and destructor
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}
Account::~Account(void)
{
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

//Getters
int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
	return _amount;
}

//Displayers

// Obtém o tempo atual como um valor time_t
// Converte time_t para a estrutura tm local
// Buffer para armazenar a string formatada: 17 caracteres (16 do formato + '\0')
// strftime formata a data e hora no buffer:
// [%Y - ano(4), %m - mês(2), %d - dia(2), _ , %H - hora(2), %M - minuto(2), %S - segundo(2)]
// Imprime o timestamp no formato [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *lt = std::localtime(&t);
	char buffer[18]; 
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", lt);
	std::cout << buffer;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" <<_nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl; 
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//Withdraw and Deposit

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:";

	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	int prevAmount = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << prevAmount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}
