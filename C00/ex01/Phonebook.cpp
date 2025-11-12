
#include "Phonebook.hpp"


Phonebook::Phonebook(void) : number_of_contacts(0)
{
	std::cout << "Phonebook Created" << std:: endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook Destroyed" << std:: endl;
	return;
}
void Phonebook::add_contact(void)
{
	Contact_Class temp;

	temp.add_first_name();
	temp.add_last_name();
	temp.add_nickname();
	temp.add_telephone();
	temp.add_darkest_secret();
	
	Contacts[number_of_contacts % 8] = temp;
	number_of_contacts++;
	std::cout << "Contact added successfully!" << std::endl;
	if (number_of_contacts >= 8)
		std::cout << "Phonebook is full! If new contact is added, old one will be replaced" << std::endl;
}

void Phonebook::display_header() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
}

std::string Phonebook::truncate_string(const std::string& str) const
{
	if (str.length() <= 10) return str;
	return str.substr(0, 9) + ".";
}

void Phonebook::search_contact(void) const
{
	if (this->number_of_contacts == 0)
	{
		std::cout << "Phonebook empty" << std:: endl;
		return;
	}
	display_header();
	int d = this->number_of_contacts;
	if (d > 8)
		d = 8;
	for (int i = 0; i < 8; ++i)
		displayCompactContent(i);
	std::string index;
	std::cout << "Enter index to view details: ";
	std::getline(std::cin, index);
	for (std::string::size_type i = 0; i < index.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(index[i])))
		{
			std::cout << "Invalid index input." << std::endl;
			return;
		}
	}
	std::istringstream iss(index);
	int n;
	if (!(iss >> n))
	{
		std::cout << "Invalid index input." << std::endl;
		return;
	}
	n -= 1;
	if (n < 0 || n >= d)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	const Contact_Class& c = this->Contacts[n];
	std::cout << "First Name: " << c.get_first_name() << std::endl;
	std::cout << "Last Name: "  << c.get_last_name()  << std::endl;
	std::cout << "Nickname: "   << c.get_nickname()  << std::endl;
	std::cout << "Phone Number: " << c.get_telephone() << std::endl;
	std::cout << "Darkest Secret: " << c.get_darkest_secret() << std::endl;

}

void Phonebook::displayCompactContent(int index) const
{
	std::cout << std::setw(10) << std::right << (index + 1) << "|";
	std::cout << std::setw(10) << std::right << truncate_string(this->Contacts[index].get_first_name()) << "|";
	std::cout << std::setw(10) << std::right << truncate_string(this->Contacts[index].get_last_name()) << "|";
	std::cout << std::setw(10) << std::right << truncate_string(this->Contacts[index].get_nickname()) << "|" << std::endl;
}

