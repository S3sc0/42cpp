#include "phonebook.hpp"

std::string	phonebook::truncate(const std::string &str)
{
	std::string	tmp;

	tmp = str;
	if (str.length() >= 10)
	{
		tmp.resize(10);
		tmp[9] = '.';
	}
	return (tmp);
}

void	phonebook::print_contact(void)
{
	std::cout << "     Index|" << "First Name|" << " Last Name|" << "  Nickname|\n";
	for (int i = 0; i < contact::filled; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << phonebook::truncate(m_contact[i].first_name) << "|";
		std::cout << std::setw(10) << phonebook::truncate(m_contact[i].last_name) << "|";
		std::cout << std::setw(10) << phonebook::truncate(m_contact[i].nickname) << "|" << std::endl;
	}
}

void	phonebook::search(void)
{
	int		i;
	std::string	index;

	print_contact();
	std::cout << "Enter your index: ";
	getline(std::cin, index);
	if (index.find_first_not_of("0123456789") == std::string::npos)
		i = stoi(index);
	while (index.find_first_not_of("0123456789") != std::string::npos || i < 0 || i >= contact::filled)
	{
		std::cout << "Enter your index: ";
		getline(std::cin, index);
		if (index.find_first_not_of("0123456789") == std::string::npos)
			i = stoi(index);
	}
	std::cout << "First Name: " << m_contact[i].first_name << std::endl;
	std::cout << "Last Name: " << m_contact[i].last_name << std::endl;
	std::cout << "Nickname: " << m_contact[i].nickname << std::endl;
	std::cout << "Phone Number: " << m_contact[i].phone_number << std::endl;
	std::cout << "Darkest Secret: " << m_contact[i].darkest_secret << std::endl;
}

void	phonebook::add(void)
{
	std::cout << "First Name: ";
	getline(std::cin, m_contact[contact::spot].first_name);
	std::cout << "Last Name: ";
	getline(std::cin, m_contact[contact::spot].last_name);
	std::cout << "Nickname: ";
	getline(std::cin, m_contact[contact::spot].nickname);
	std::cout << "Phone Number: ";
	getline(std::cin, m_contact[contact::spot].phone_number);
	while (m_contact[contact::spot].phone_number.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Phone number is unvalid try again\nPhone Number: ";
		getline(std::cin, m_contact[contact::spot].phone_number);
	}
	std::cout << "Darkest Secret: ";
	getline(std::cin, m_contact[contact::spot].darkest_secret);
	m_contact->increment();
}

void	phonebook::verify_command(const std::string& command)
{
	if (command == "EXIT")
		exit(0);
	else if (command == "ADD")
		add();
	else if (command == "SEARCH")
		search();
}