#include "PmergeMe.hpp"

// Entry point: takes a sequence of positive integers as arguments,
// sorts them with Ford-Johnson using std::vector and std::list and prints
// the result and the time of each one. Any invalid input prints "Error"
// on stderr.
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	try
	{
		sorter.run(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
