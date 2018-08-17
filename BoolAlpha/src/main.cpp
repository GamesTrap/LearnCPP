#include <iostream>

int main()
{
	char c;

	std::cin >> c;
	const bool isCaptialLetter = (c >= 'A') && (c <= 'Z');
	std::cout.setf(std::ios_base::boolalpha); //Turn on text format
	std::cout << isCaptialLetter << '\n'; //Convert to text
	std::cout.unsetf(std::ios_base::boolalpha); //Turn off text format
	std::cout << isCaptialLetter << '\n'; //1 or 0

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}