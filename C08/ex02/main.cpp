#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<int, std::list<int> > listStack;
	listStack.push(1);
	listStack.push(2);
	listStack.push(3);
	for (MutantStack<int, std::list<int> >::iterator lit = listStack.begin(); lit != listStack.end(); ++lit)
		std::cout << *lit << " ";
	std::cout << std::endl;

	return (0);
}
