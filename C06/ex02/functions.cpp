#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	switch (std::rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::bad_cast &) {
		std::cout << "Unknown" << std::endl;
	}
}
