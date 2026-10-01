#include "RPN.hpp"

// Entry point: takes one argument with the reverse polish expression,
// prints the result on stdout or "Error" on stderr.
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn;
	try
	{
		std::cout << rpn.calculate(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
