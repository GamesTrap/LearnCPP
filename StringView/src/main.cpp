#include <iostream>

#include "StringView.h"

int main()
{
	StringView emptyStringView;
	std::cout << "Empty StringView. Length = " << emptyStringView.length() << '\n';

	StringView stringView("Hello");
	std::cout << "Hello: Length = " << stringView.length() << '\n';
	display(std::cout, stringView);
	std::cout << '\n' << "Character by character:" << '\n';
	for (char i : stringView)
		std::cout << '*' << i;
	std::cout << '*' << '\n';
	for (auto c : stringView)
		std::cout << '_' << c;
	std::cout << '_' << '\n';
	const StringView secondStringView = stringView;
	std::cout << "Assgiend StringView: ";
	display(std::cout, secondStringView);
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}