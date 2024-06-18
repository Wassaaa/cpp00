#include "Contact.hpp"

class PhoneBook
{
private:
	static const int size = 8;
	Contact	contacts[size];
	void	add_contact(void);
	void	search_contact(void);
	void	create_contact(
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret
	);
	void	print_contacts(void);
public:
	static void	run(void);
	PhoneBook(void);
	~PhoneBook(void);
};
