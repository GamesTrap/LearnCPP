#include <iostream>

int main()
{
	std::cout << "Calculation of the first prime number, which is >= the number entered" << '\n';

	long z;

	//do while loop for input and plausibility check
	do
	{
		//Query as long as z <= 3
		std::cout << "Please enter a number > 3: ";
		std::cin >> z;
	} while (z <= 3);

	//If z is event, the next odd number is taken as the starting value.
	if (z % 2 == 0)
		++z;
	bool found{ false };

	do
	{
		//limit = limit up to which must be calculated.
		//sqrt() works with double, so the type is explicitly cast.
		const long limit{ 1 + static_cast<long>(sqrt(static_cast<double>(z))) };
		long rest;
		long divider{ 1 };

		do //Divide candidate z by all odd divisors
		{
			divider += 2;
			rest = z % divider;
		} while (rest > 0 && divider < limit);

		if (rest > 0 && divider >= limit)
			found = true;
		else //Otherwise check next odd number:
			z += 2;
	} while (!found);
	std::cout << "The next prime number is " << z << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}