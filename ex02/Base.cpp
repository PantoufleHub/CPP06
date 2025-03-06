#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <unistd.h>
#include <ctime>

Base::~Base (){}

Base *generate()
{
	srand((time(NULL)));
	int rnd = rand() % 3;

	switch (rnd)
	{
	case 0:
		std::cout << "Generated instance of A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Generated instance of B" << std::endl;
		return (new B);
	case 2:
		std::cout << "Generated instance of C" << std::endl;
		return (new C);
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	std::cout << "Pointer of type ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base &r)
{
	std::cout << "Reference of type ";
	try {
		A &	a = dynamic_cast<A &>(r);
		(void) a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::exception& e) {}
	try {
		B &	b = dynamic_cast<B &>(r);
		(void) b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::exception& e) {}
	try {
		C &	c = dynamic_cast<C &>(r);
		(void) c;
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::exception& e) {}
	std::cout << "Unknown" << std::endl;
}
