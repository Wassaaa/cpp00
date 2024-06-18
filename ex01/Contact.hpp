#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
private:
	bool		is_empty;
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	nickname;
	std::string	darkest_secret;
public:

	Contact();
	~Contact();
	bool	is_valid(void);
	void	print_contact(void);
	void	print_details(void);
	void	set(
		int			index,
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret
	);
};

#endif
