#include "PhoneBook.hpp"

void PhoneBook::run(void)
{
	std::string	command;
	PhoneBook	phone_book;

	while (42)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			phone_book.add_contact();
		if (command == "SEARCH")
			phone_book.search_contact();
		std::cout << "Invalid command!" << std::endl;
	}
}

std::string ask_info(std::string field)
{
	std::string field_value;

	std::cout << field + ": ";
	std::getline(std::cin, field_value);
	return (field_value);
}

void PhoneBook::add_contact(void)
{
	static int	i = 0;
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	darkest_secret;
	Contact contact;

	i = i % 8;
	first_name = ask_info("First name");
	first_name = ask_info("Last name");
	first_name = ask_info("Phone number");
	first_name = ask_info("Darkest Secret");
	contact.set(first_name, last_name, phone_number, darkest_secret);
	this->contacts[i] = contact;
}

void	PhoneBook::search_contact(void)
{
 return ;
}

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
