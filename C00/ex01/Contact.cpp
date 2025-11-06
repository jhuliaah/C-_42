
#include "Contact.hpp"

void	add_first_name(std::string first_name) {

	std::cout << "First name: ";
	getline(std::cin, first_name);
	if (first_name.empty()){
		std::cout << "Field can't be blank." << std::endl;
		first_name(first_name);
	}
}

void	add_last_name(std::string last_name) {

	std::cout << "First name: ";
	getline(std::cin, last_name);
	if (last_name.empty()){
		std::cout << "Field can't be blank." << std::endl;
		add_last_name(last_name);
	}

}

void	add_nickname(std::string nickname) {

	std::cout << "Nickname: ";
	getline(std::cin, nickname);
	if (nickname.empty()) {
		std::cout << "Field can't be blank." << std::endl;
		add_nickname(nickname);
	}
}

void	add_telephone(std::string telephone) {

	std::cout << "Telephone (only digits): ";
	getline(std::cin, telephone);
	if (!is_only_number(telephone))
	{
		std::cout << "Telephone needs to be only digits" << std::endl;
		add_telephone(telephone);
	}
	else if (telephone.empty()) {
		std::cout << "Field can't be blank." << std::endl;
		add_telephone(telephone);
	}
}

void	add_darkest_secret(std::string darkest_secret) {

	std::cout << "Give me your darkest secret: ";
	getline(std::cin, darkest_secret);
	if (darkest_secret.empty()) {
		std::cout << "Field can't be blank." << std::endl;
		add_darkest_secret(darkest_secret);
	}
}

bool	is_only_number(std::string telephone) {

	for (int i = 0; i < strlen(telephone.c_str()); i++)
	{
		if (!isdigit(telephone.c_str()[i]))
			return (false);
	}
	return (true);
}


std::string Contact_Class::get_first_name(void) const
{
	return (this->first_name);
}

std::string	Contact_Class::get_last_name(void) const
{
	return (this->last_name);
}

std::string	Contact_Class::get_nickname(void) const
{
	return (this->nickname);
}

std::string	Contact_Class::get_telephoner(void) const
{
	return (this->telephone);
}

std::string	Contact_Class::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}

Contact_Class::Contact(void){
	return;
}

Contact_Class::~Contact(void){
	return;
}