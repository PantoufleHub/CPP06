#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *b = generate();

	identify(b);
	identify(*b);

	delete b;
	return 0;
}
