#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &elem) {
	std::cout << elem << " ";
}

void increment(int &elem) {
	elem++;
}

int main(void) {
	int ints[5] = {1, 2, 3, 4, 5};

	std::cout << "before: ";
	::iter(ints, 5, print<int>);
	std::cout << std::endl;

	::iter(ints, 5, increment);

	std::cout << "after:  ";
	::iter(ints, 5, print<int>);
	std::cout << std::endl;

	std::string strings[3] = {"foo", "bar", "baz"};
	::iter(strings, 3, print<std::string>);
	std::cout << std::endl;

	int const consts[3] = {7, 8, 9};
	::iter(consts, 3, print<int>);
	std::cout << std::endl;

	return (0);
}
