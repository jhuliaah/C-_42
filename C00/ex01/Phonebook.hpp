
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

class	Phonebook{

	private:

	int						number_of_contacts;
	Contacts_class			Contacts[8];

	Contact::Contact_class	get_contact(int id);
	std::string 			truncate_string(std::string& str) const;
	std::string				get_input(std::string& prompt) const;
	std::string				display_contact_truncate(int id);
	void					display_header(void);

	public:
	phonebook(void);
	~phonebook(void);

	void					search_contact(void);
	void					add_contact(void);
};

#endif