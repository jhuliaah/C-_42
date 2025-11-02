
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <limits>

class	Contact_Class {

	private:

	int	id;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	telephone;

	
	public:
	
	Contact(void);
	~Contact(void);
	
	bool	is_only_number(std::string telephone);
	void	add_first_name(std::string first_name);
	void	add_last_name(std::string last_name);
	void	add_nickname(std::string nickname);
	void	add_telephone(std::string telephone);
	void	add_darkest_secret(std::string darkest_secret);

	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_telephone(void) const;
	std::string	get_darkest_secret(void) const;

};

#endif