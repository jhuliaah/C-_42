#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i * 2);

	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "found in vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 99);
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "found in list: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	return (0);
}
