#include "Contact.hpp"

class PhoneBook
{
private:
	int	index;
	static const int size = 8;
	Contact	contacts[size];
	void	add_contact(void);
	void	search_contact(void);
public:
	static void	run(void);
	PhoneBook(void);
	~PhoneBook(void);
};
