#include <iostream>

#include "DerivedClass.h"

int main()
{
	DerivedClass d1("Hi", 42); //General constructor
	std::cout << d1.getAttribute() << ' ' << d1.getValue() << '\n';

	DerivedClass d2("Hello World!"); //Inherited constructor
	std::cout << d2.getAttribute() << ' ' << d2.getValue() << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
