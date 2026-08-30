
#include "Harl.hpp"

//Constructor

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplopicles-ketchup-especial. Eu realmente amo!" << std::endl;
	return;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
				"You didn't put enough bacon in my burger! "
				"If you did, I wouldn't be asking for more!"
				<< std::endl;
	return;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. "
				"I've been coming for years whereas you started working here since last month."
				<< std::endl;
	return;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! "
				"I want to speak to the manager now."
				<< std::endl;
	return;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*comments[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*comments[i])();
			return;
		}
	}
	std::cout << "Level not found." << std::endl;
}

/*
** HARL::COMPLAIN
**
** This function implements a lookup table mechanism to map a string input
** (level) to a private member function call (debug, info, etc.).
**
** It avoids using long 'if/else if' or 'switch' statements by utilizing
** C++ Pointers to Member Functions.
**
** 1. Lookup Tables:
** - 'levels': An array of strings used to validate the input and find its index.
** - 'comments': An array of Pointers to Member Functions, where the index
** corresponds to the 'levels' array.
**
** 2. Execution Logic:
** - The loop finds a matching string in 'levels'.
** - The corresponding index 'i' is used to select the correct function pointer
** from the 'comments' array.
** - The function is invoked using the special C++ syntax for
** Pointer-to-Member invocation: (this->*comments[i])().
**
** This ensures the correct log function is called dynamically based on the string input.
*/