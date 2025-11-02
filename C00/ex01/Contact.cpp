
#include "Contact.hpp"

void	add_first_name(std::string first_name) {

	std::cout << "First name: ";
	getline(std::cin, first_name);
}

void	add_last_name(std::string last_name) {

	std::cout << "First name: ";
	getline(std::cin, last_name);
}

void	add_nickname(std::string nickname) {

	std::cout << "First name: ";
	getline(std::cin, nickname);
}

void	add_telephone(std::string telephone) {

	std::cout << "Telephone (only numbers): ";
	getline(std::cin, telephone);
	if (!is_only_number(telephone))
}

void	add_darkest_secret(std::string darkest_secret) {

	std::cout << "Give me your darkest secret: ";
	getline(std::cin, darkest_secret);
}

bool	is_only_number(std::string telephone) {

	for (int i = 0; i < strlen((const char *)telephone); i++)

}



std:string	get_first_name(void) const;
std:string	get_last_name(void) const;
std:string	get_nickname(void) const;
std:string	get_telephone(void) const;
std:string	get_darkest_secret(void) const;