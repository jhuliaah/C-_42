#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <utility>
# include <algorithm>
# include <climits>
# include <ctime>
# include <iomanip>
# include <exception>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;

		std::vector<int>	sortVector(const std::vector<int> &input);
		std::list<int>		sortList(const std::list<int> &input);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		//error treatment

		class ErrorException : public std::exception {
			public:
			virtual const char* what() const throw() { return "Error"; }
		};

		//functions:

		void	run(int argc, char **argv);
};

#endif
