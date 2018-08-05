#include <iostream>

int main()
{
	if (std::numeric_limits<char>::is_signed)
		std::cout << "char is interpreted as signed on this system." << '\n';
	else
		std::cout << "char is interpreted as unsigned on this system." << '\n';

	std::cout << '\n' << "Limits for char, converted to int:" << '\n';
	std::cout << "Minimum = " << static_cast<int>(std::numeric_limits<char>::min()) << '\n';
	std::cout << "Maximum = " << static_cast<int>(std::numeric_limits<char>::max()) << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}