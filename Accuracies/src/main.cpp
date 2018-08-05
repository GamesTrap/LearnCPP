#include <iostream>

int main()
{
	std::cout << "The accuracy of float is about " << std::numeric_limits<float>::digits10 << " decimal places." << '\n';
	std::cout << "The accuracy of double is about " << std::numeric_limits<double>::digits10 << " decimal places." << '\n';
	std::cout << "The accuracy of long double is about " << std::numeric_limits<long double>::digits10 << " decimal places." << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}