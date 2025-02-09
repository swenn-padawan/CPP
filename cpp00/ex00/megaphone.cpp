#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for(int i = 1; i < argc; i++)
	{
		for(std::size_t j = 0; argv[i][j]; j++)
			argv[i][j] = std::toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << "\n";
}
