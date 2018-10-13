#include <iostream>

#include "Date.h"

int main()
{
	Date d1;
	++d1;
	//std::string dateString = d1; //Implicit type conversion not allowed because of explicit
	std::cout << "Explicit type conversion: ";
	const std::string dateString = static_cast<std::string>(d1);
	std::cout << dateString << '\n';

	constexpr Date d2(1, 1, 2017);
	std::cout << d2.month() << '/' << d2.day() << '/' << d2.year() << '\n';
	Date d3 = d2;
	++d3;
	std::cout << d3.month() << '/' << d3.day() << '/' << d3.year() << '\n';

	++d3;
	std::cout << d3 << '\n';

	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}