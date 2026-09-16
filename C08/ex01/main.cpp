#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest:  " << sp.longestSpan() << std::endl;

	Span big(10000);
	std::vector<int> range;
	for (int i = 0; i < 10000; i++)
		range.push_back(i);
	big.addRange(range.begin(), range.end());
	std::cout << "big shortest: " << big.shortestSpan() << std::endl;
	std::cout << "big longest:  " << big.longestSpan() << std::endl;

	try {
		Span empty(1);
		empty.addNumber(1);
		empty.addNumber(2);
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	try {
		Span tooSmall(1);
		tooSmall.shortestSpan();
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	return (0);
}
