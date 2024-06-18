#include "Contact.hpp"

void Contact::set(
		int			index,
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret
	)
{
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	this->nickname = nickname;
	this->is_empty = false;
}

bool Contact::is_valid(void)
{
	if (this->is_empty)
		return (false);
	return (true);
}

std::string	fix_print_width(std::string str)
{
	int	len;

	len = str.length();
	if (len > 10)
		return (str.substr(0, 9) + ".\0");
	else
	{
		while (len++ < 10)
			str = " " + str;
		return (str);
	}
}

void Contact::print_details(void)
{
	std::cout << "################  DETAILS  ################" << std::endl;
	std::cout << "First Name: "<< this->first_name << std::endl;
	std::cout << "Last Name: "<< this->last_name << std::endl;
	std::cout << "Nickname: "<< this->nickname << std::endl;
	std::cout << "Phone Number: "<< this->phone_number << std::endl;
	std::cout << "Darkest Secret: "<< this->darkest_secret << std::endl;
	std::cout << "###########################################" << std::endl;
}

void Contact::print_contact(void)
{
	if (!this->is_empty)
	{
		std::cout << fix_print_width(std::to_string(this->index)) << "|";
		std::cout << fix_print_width(this->first_name) << "|";
		std::cout << fix_print_width(this->last_name) << "|";
		std::cout << fix_print_width(this->nickname) << std::endl;
	}
}

Contact::Contact(void)
{
	this->is_empty = true;
	return ;
}
Contact::~Contact(void)
{
	this->is_empty = true;
	return ;
}
