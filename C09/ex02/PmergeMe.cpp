#include "PmergeMe.hpp"

//==========================================//
//				CONSTRUCTORS				//
//==========================================//

// Default constructor: both containers start empty.
PmergeMe::PmergeMe() {}

// Copy constructor: copies both containers.
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _list(other._list) {}

// Assignment operator: copies both containers from another object.
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_list = other._list;
	}
	return *this;
}

// Destructor: nothing to free, the containers clean themselves up.
PmergeMe::~PmergeMe() {}

//==========================================//
//				PARSING						//
//==========================================//

// Converts one token to a positive int. Only digits are accepted
// (no sign, no letters) and the value must be between 1 and INT_MAX.
// Throws ErrorException otherwise.
static int parseNumber(const std::string &token) {
	if (token.empty() || token.size() > 10)
		throw PmergeMe::ErrorException();
	for (std::size_t i = 0; i < token.size(); i++) {
		if (!isdigit(static_cast<unsigned char>(token[i])))
			throw PmergeMe::ErrorException();
	}
	long value = atol(token.c_str());
	if (value <= 0 || value > INT_MAX)
		throw PmergeMe::ErrorException();
	return static_cast<int>(value);
}

// Reads every argument and returns all the numbers found, in order.
// An argument can hold more than one number ("3 5 9"), so each one is
// split by spaces. Throws if there is no number at all.
static std::vector<std::string> readTokens(int argc, char **argv) {
	std::vector<std::string> tokens;
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
			tokens.push_back(token);
	}
	if (tokens.empty())
		throw PmergeMe::ErrorException();
	return tokens;
}

//==========================================//
//				VECTOR						//
//==========================================//

// Ford-Johnson (merge-insertion) sort with std::vector:
// 1. split the numbers in pairs and put the biggest of each pair first
//    (an odd number out is kept aside as the "straggler")
// 2. recursively sort the biggest numbers of each pair -> "main chain"
// 3. put the pairs back in the order of the sorted main chain
// 4. the small partner of the first pair is smaller than everything in the
//    chain, so it goes straight to the front
// 5. insert the other small numbers ("pend") with binary search, in the
//    Jacobsthal order (3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, ...). Each one
//    only needs to be searched up to the position of its big partner,
//    which keeps the number of comparisons as low as possible.
std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
	if (input.size() <= 1)
		return input;

	// 1. make the pairs (big, small)
	std::vector< std::pair<int, int> > pairs;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}
	bool hasStraggler = (input.size() % 2 != 0);
	int straggler = hasStraggler ? input[input.size() - 1] : 0;

	// 2. recursively sort the big numbers
	std::vector<int> bigs;
	for (std::size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);
	std::vector<int> chain = sortVector(bigs);

	// 3. reorder the pairs to follow the sorted chain (each pair is used
	//    only once, so repeated numbers still get the right partner)
	std::vector< std::pair<int, int> > sortedPairs;
	for (std::size_t i = 0; i < chain.size(); i++) {
		for (std::size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == chain[i]) {
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	// 4. first small number goes to the front
	chain.insert(chain.begin(), sortedPairs[0].second);

	// pend[k] = small number to insert, its big partner is sortedPairs[k].first
	// (the straggler, if any, is the last one and has no partner)
	std::size_t pendSize = sortedPairs.size() + (hasStraggler ? 1 : 0);

	// 5. insert in Jacobsthal order. With 1-based indexes, b1 is already in,
	//    then groups go from the next Jacobsthal number down to the previous
	//    one: b3 b2, b5 b4, b11..b6, b21..b12 ...
	std::size_t prevJacob = 1;
	std::size_t currJacob = 3;
	while (prevJacob < pendSize) {
		std::size_t groupEnd = std::min(currJacob, pendSize);
		for (std::size_t b = groupEnd; b > prevJacob; b--) {
			std::size_t k = b - 1;
			int value;
			std::vector<int>::iterator bound;
			if (k < sortedPairs.size()) {
				value = sortedPairs[k].second;
				bound = std::find(chain.begin(), chain.end(), sortedPairs[k].first);
			} else {
				value = straggler;
				bound = chain.end();
			}
			chain.insert(std::lower_bound(chain.begin(), bound, value), value);
		}
		std::size_t next = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = next;
	}
	return chain;
}

//==========================================//
//				LIST						//
//==========================================//

// Same Ford-Johnson steps as sortVector, but with std::list. A list has no
// random access, so positions are reached with iterators / std::advance.
std::list<int> PmergeMe::sortList(const std::list<int> &input) {
	if (input.size() <= 1)
		return input;

	// 1. make the pairs (big, small)
	std::list< std::pair<int, int> > pairs;
	std::list<int>::const_iterator it = input.begin();
	while (it != input.end()) {
		int first = *it;
		++it;
		if (it == input.end())
			break;
		int second = *it;
		++it;
		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	bool hasStraggler = (input.size() % 2 != 0);
	int straggler = hasStraggler ? input.back() : 0;

	// 2. recursively sort the big numbers
	std::list<int> bigs;
	for (std::list< std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
		bigs.push_back(p->first);
	std::list<int> chain = sortList(bigs);

	// 3. reorder the pairs to follow the sorted chain
	std::list< std::pair<int, int> > sortedPairs;
	for (std::list<int>::iterator c = chain.begin(); c != chain.end(); ++c) {
		for (std::list< std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p) {
			if (p->first == *c) {
				sortedPairs.push_back(*p);
				pairs.erase(p);
				break;
			}
		}
	}

	// 4. first small number goes to the front
	chain.push_front(sortedPairs.front().second);

	std::size_t pendSize = sortedPairs.size() + (hasStraggler ? 1 : 0);

	// 5. insert in Jacobsthal order (see sortVector)
	std::size_t prevJacob = 1;
	std::size_t currJacob = 3;
	while (prevJacob < pendSize) {
		std::size_t groupEnd = std::min(currJacob, pendSize);
		for (std::size_t b = groupEnd; b > prevJacob; b--) {
			std::size_t k = b - 1;
			int value;
			std::list<int>::iterator bound;
			if (k < sortedPairs.size()) {
				std::list< std::pair<int, int> >::iterator p = sortedPairs.begin();
				std::advance(p, k);
				value = p->second;
				bound = std::find(chain.begin(), chain.end(), p->first);
			} else {
				value = straggler;
				bound = chain.end();
			}
			chain.insert(std::lower_bound(chain.begin(), bound, value), value);
		}
		std::size_t next = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = next;
	}
	return chain;
}

//==========================================//
//				RUN							//
//==========================================//

// Prints every number of the container separated by spaces.
template <typename T>
static void printSequence(const std::string &label, const T &container) {
	std::cout << label;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

// Returns the time elapsed between start and end in microseconds.
static double elapsedUs(std::clock_t start, std::clock_t end) {
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

// Parses the arguments, sorts them with both containers and prints:
// the sequence before, the sequence after, and the time each container
// took. The time includes filling the container (data management) and
// sorting it. Throws ErrorException on invalid input.
void PmergeMe::run(int argc, char **argv) {
	std::vector<std::string> tokens = readTokens(argc, argv);

	// std::vector: fill + sort
	std::clock_t startVec = std::clock();
	_vec.clear();
	for (std::size_t i = 0; i < tokens.size(); i++)
		_vec.push_back(parseNumber(tokens[i]));
	std::vector<int> sortedVec = sortVector(_vec);
	std::clock_t endVec = std::clock();

	// std::list: fill + sort
	std::clock_t startList = std::clock();
	_list.clear();
	for (std::size_t i = 0; i < tokens.size(); i++)
		_list.push_back(parseNumber(tokens[i]));
	std::list<int> sortedList = sortList(_list);
	std::clock_t endList = std::clock();

	printSequence("Before:", _vec);
	printSequence("After: ", sortedVec);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << elapsedUs(startVec, endVec) << " us" << std::endl;
	std::cout << "Time to process a range of " << _list.size()
			  << " elements with std::list   : " << elapsedUs(startList, endList) << " us" << std::endl;
}
