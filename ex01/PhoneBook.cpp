#include "PhoneBook.hpp"

void PhoneBook::run(void)
{
	std::string	command;
	PhoneBook	phone_book;

	phone_book.create_contact("John12345678", "Smith", "john2", "1234567890", "I am John Smith");
	phone_book.create_contact("John", "Doe", "john", "1234567890", "I am John Doe");
	phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	// phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	// phone_book.create_contact("Jane", "Doe", "jane", "0987654321", "I am Jane Doe");
	// phone_book.create_contact("duped", "Doe", "jane", "0987654321", "I am Jane Doe");
	// phone_book.create_contact("twice", "Doe", "jane", "0987654321", "I am Jane Doe");

	while (42)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(1);
		if (command == "EXIT")
			break ;
		if (command == "ADD")
		{
			phone_book.add_contact();
			continue;
		}
		if (command == "SEARCH")
		{
			phone_book.search_contact();
			continue;
		}
		if (command.empty())
			continue;
		std::cout << "Invalid command!" << std::endl;
	}
}

bool	all_digits(std::string str)
{
	for (char c : str)
		if (!std::isdigit(c))
			return (false);
	return (true);
}

bool	check_number(std::string field, std::string field_value)
{
	if (field != "Phone number")
		return (true);
	if (!all_digits(field_value))
		return (false);
	return (true);
}

bool has_printable(std::string str)
{
	for (char c : str)
		if (std::isprint(c) && !std::isspace(c))
			return (true);
	return (false);
}

std::string	ask_info(std::string field)
{
	std::string field_value;

	while (42)
	{
		std::cout << field + ": ";
		std::getline(std::cin, field_value);
		if (std::cin.eof())
			exit(1);
		if (field_value.empty() || !has_printable(field_value))
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		if (!check_number(field, field_value))
		{
			std::cout << "Phone number must be all digits" << std::endl;
			continue ;
		}
		break ;
	}
	return (field_value);
}

void	PhoneBook::add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	Contact contact;

	first_name = ask_info("First name");
	last_name = ask_info("Last name");
	nickname = ask_info("Nickname");
	phone_number = ask_info("Phone number");
	darkest_secret = ask_info("Darkest Secret");
	this->create_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void	PhoneBook::print_contacts(void)
{
	int	i = 0;
	while (i < this->size)
	{
		this->contacts[i].print_contact();
		i++;
	}
	return ;
}

void	PhoneBook::check_contact(Contact contacts[PhoneBook::size])
{
	std::string	index_string;
	int			index_to_check;

	while (42)
	{
		std::cout << "Enter an index to check (0 - " << PhoneBook::size - 1 << "): ";
		std::getline(std::cin, index_string);
		if (std::cin.eof())
			exit(1);
		if (index_string.empty() || !all_digits(index_string))
		{
			std::cout << "Invalid index!" << std::endl;
			continue ;
		}
		index_to_check = std::stoi(index_string);
		if (index_to_check < 0 || index_to_check > this->size - 1)
		{
			std::cout << "Invalid index!, Back to the start" << std::endl;
			return ;
		}
		if (contacts[index_to_check].is_valid())
		{
			contacts[index_to_check].print_details();
			return ;
		}
		else
			std::cout << "Contact is empty at that index" << std::endl;
	}
}

void	PhoneBook::search_contact(void)
{
	int	i = 0;
	std::string index_to_check;

	std::cout << "###############  CONTACTS  ################" << std::endl;
	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	while (i < this->size)
	{
		this->contacts[i].print_contact();
		i++;
	}
	check_contact(this->contacts);
	return ;
}

void PhoneBook::create_contact(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret
)
{
	Contact 	contact;
	static int	i = 0;

	contact.set(i, first_name, last_name, nickname, phone_number, darkest_secret);
	this->contacts[i] = contact;
	i = (i + 1) % 8;
}

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
