#include <iostream>
#include <string>

std::string	to_upper(std::string str)
{
	int	len;
	int	i;

	len = str.length();
	i = 0;
	while (i < len)
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(int argc, char const *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while(*argv)
			std::cout << to_upper(*argv++);
		std::cout << std::endl;
	}
	return (0);
}
