#include "Harl.hpp"
#include <cstring>
int switch_function(char *argv)
{
	char	level[][8] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	for (int i = 0; i < 4; i++){
		if (!strcmp(level[i], argv)) return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	Harl	harl;

	switch (switch_function(argv[1])) {
		case DEBUG: harl.complain("DEBUG");
		case INFO: harl.complain("INFO");
		case WARNING: harl.complain("WARNING");
		case ERROR: harl.complain("ERROR");
		return (0);
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}
