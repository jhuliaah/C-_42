
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

class	Phonebook{

	private:

	Contact_Class			get_contact(int id);
	std::string 			truncate_string(const std::string& str) const;
	std::string				get_input(std::string& prompt) const;
	//std::string				display_contact_truncate(int id);
	void					display_header(void) const;

	public:
	
	int						number_of_contacts;
	Contact_Class			Contacts[8];
	
	Phonebook(void);
	~Phonebook(void);

	void					search_contact(void) const;
	void					add_contact(void);
	void					displayCompactContent(int index) const;
	
};

#endif