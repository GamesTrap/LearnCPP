#include <iostream>

int main()
{
	std::cout << "The accuracy of float is about " << std::numeric_limits<float>::digits10 << " decimal places." << '\n';
	std::cout << "The accuracy of double is about " << std::numeric_limits<double>::digits10 << " decimal places." << '\n';
	std::cout << "The accuracy of long double is about " << std::numeric_limits<long double>::digits10 << " decimal places." << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}