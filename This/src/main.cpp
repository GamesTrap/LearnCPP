#include <iostream>

#include "This.h"

int main()
{
	This t;
	t.add(1); //Return value is ignored
	std::cout << t.get() << '\n'; //1
	t.add(2).add(3); //*** chaining of calls
	std::cout << t.get() << '\n'; //6
	This a, b;
	a.assign(b.assign(t)); //corresponds to a = b = t;
	std::cout << a.get() << '\n'; //6

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}