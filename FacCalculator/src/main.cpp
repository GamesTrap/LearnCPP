#include <iostream>

int main()
{
	std::cout << "Please enter a number >= 0: ";
	unsigned int n;
	std::cin >> n;

	unsigned long fac{ 1L };
	for (unsigned int i = 2; i <= n; ++i)
		fac *= i;
	std::cout << "!   =   " << fac << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}