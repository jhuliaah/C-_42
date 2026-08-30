
#include <iostream>
#include <fstream>
#include <string>

void	replace_in_file(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file!" << filename << std::endl;
		return;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create file!" << filename + "replace" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		std::string result;
		size_t start =0;
		size_t found;
		while ((found = line.find(s1, start)) != std::string::npos)
		{
			result += line.substr(start, found - start);
			result += s2;
			start = found + s1.length();
		}
		result += line.substr(start);
		outfile << result << std::endl;
	}
	infile.close();
	outfile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	if (s2.empty())
	{
		std::cerr << "Error: s2 cannot be empty" << std::endl;
		return (1);
	}

	replace_in_file(filename, s1, s2);
	return (0);
}