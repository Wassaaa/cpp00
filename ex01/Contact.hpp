#include <iostream>

class Contact
{
private:
	int		index;
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	nickname;
	std::string	darkest_secret;
public:

	Contact();
	~Contact();
	void	set(
		std::string first_name,
		std::string last_name,
		std::string phone_number,
		std::string darkest_secret
	);
};