
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstddef>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <limits>
#include <string>

class	Contact_Class {

	private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	telephone;

	
	public:
	
	Contact_Class(void);
	~Contact_Class();
	
	bool	is_only_number(std::string telephone);
	void	add_first_name(void);
	void	add_last_name(void);
	void	add_nickname(void);
	void	add_telephone(void);
	void	add_darkest_secret(void);

	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_telephone(void) const;
	std::string	get_darkest_secret(void) const;

};

#endif