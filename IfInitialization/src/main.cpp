#include <iostream>

#include <cmath>

int main()
{
	std::cout << "Please enter a float: ";
	float input;
	std::cin >> input;

	{
		const float x = sin(input);
		if (x >= 0)
			std::cout << x << " is null or positive!" << '\n';
		else
			std::cout << x << " is negative!" << '\n';
	}

	//shorter and equivalent:
	if (const float x = sin(input); x >= 0)
		std::cout << x << " is null or positive!" << '\n';
	else
		std::cout << x << " is negative" << '\n';

	const auto f{ 8. };
	std::cout << f << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}