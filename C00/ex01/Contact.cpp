
#include "Contact.hpp"

bool	is_only_number(std::string telephone);

void	Contact_Class::add_first_name(void) {
	std::string input;
	std::cout << "First name: ";
	getline(std::cin, input);
	if (input.empty()){
		std::cout << "Field can't be blank." << std::endl;
		add_first_name();
	} else {
		this->first_name = input;
	}
}

void	Contact_Class::add_last_name(void) {

	std::string input;
	std::cout << "Last name: ";
	getline(std::cin, input);
	if (input.empty()){
		std::cout << "Field can't be blank." << std::endl;
		add_last_name();
	} else {
		this->last_name = input;
	}

}

void	Contact_Class::add_nickname(void) {

	std::string input;
	std::cout << "Nickname: ";
	getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Field can't be blank." << std::endl;
		add_nickname();
	} else {
		this->last_name = input;
	}
}

void	Contact_Class::add_telephone(void) {

	std::string input;
	std::cout << "Telephone (only digits): ";
	getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Field can't be blank." << std::endl;
		add_telephone();
	}	
	else if (!is_only_number(input))
	{
		std::cout << "Telephone needs to be only digits" << std::endl;
		add_telephone();
	}
	else
	{
		this->telephone = input;
	}
}

void	Contact_Class::add_darkest_secret(void) {

	std::string input;
	std::cout << "Give me your darkest secret: ";
	getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Field can't be blank." << std::endl;
		add_darkest_secret();
	}
	else
		this->darkest_secret = input;
}

bool	Contact_Class::is_only_number(std::string telephone) {
	if (telephone.empty())
		return (false); 
	for (std::string::size_type i = 0; i < telephone.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(telephone[i])))
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

std::string	Contact_Class::get_telephone(void) const
{
	return (this->telephone);
}

std::string	Contact_Class::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}

Contact_Class::Contact_Class(void){
	return;
}

Contact_Class::~Contact_Class(void) {
	return;
}