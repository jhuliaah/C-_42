
#include "Phonebook.hpp"
#include "Contact.hpp"

int	main(void)
{
	Contact_Class Contact;
	Phonebook phoneBook;

	while (true)
	{
		std::string command;
		std::cout << "Please insert 'ADD', 'SEARCH' or 'EXIT': ";
		std::getline(std::cin, command);
		if (command == "ADD")
			PhoneBook.addContact();
		else if (command == "SEARCH")
			PhoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
