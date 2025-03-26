#include <fstream>
#include <iostream>
#include <cstring>

#define RED "\x1b[31;4m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"

void	ft_replace(std::string &line, const std::string &replace, const std::string &by)
{
	size_t pos = 0;
	while ((pos = line.find(replace, pos)) != std::string::npos)
	{
		line.erase(pos, replace.length());
		line.insert(pos, by);
		pos += by.length();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "WOMP WOMP" << std::endl;
		return (2);
	}
	std::ifstream	fd;
	fd.open(argv[1], std::fstream::in);
	if (!fd){
		std::cout << RED << "The File Don't Exist OR I Don't Have The Permissions To Open It !" << RESET << std::endl;
		return (2);
	}
	std::cout << GREEN << "File Open Succesfully" << RESET << std::endl;
	std::string line;
	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream outfile(filename.c_str());
	while (std::getline(fd, line)){
		ft_replace(line, argv[2], argv[3]);
		outfile << line;
	}
}
