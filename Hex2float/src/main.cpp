#include <iostream>

int main()
{
	std::cout << "The hexadecimal number 0xC.68p+2 has the float value: " << 0xC.68p+2f << '\n'; //49.625

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}