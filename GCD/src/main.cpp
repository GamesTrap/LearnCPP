#include <iostream>

int main()
{
	unsigned int x, y;
	std::cout << "Enter 2 numbers > 0: ";
	std::cin >> x >> y;
	std::cout << "The GCD of " << x << " and " << y << " is ";

	while(x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	std::cout << x << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}