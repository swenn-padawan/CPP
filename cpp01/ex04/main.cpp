#include <fstream>
#include <iostream>
#include <cstring>

#define RED "\x1b[31;4m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "WOMP WOMP" << std::endl;
		return (2);
	}
	std::fstream	fd;
	fd.open(argv[1], std::fstream::in);
	if (!fd){
		std::cout << RED << "The File Don't Exist OR I Don't Have The Permissions To Open It !" << RESET << std::endl;
		return (2);
	}
	std::cout << GREEN << "File Open Succesfully" << RESET << std::endl;
	std::string line;
	std::ofstream outfile("outfile");
	while (std::getline(fd, line)){
		if (line != argv[2])
			outfile << line;
		std::cout << "line = " << line << " argv[2] = " << argv[3] << std::endl;
		//else
		 //outfile << argv[3];
	}
}
