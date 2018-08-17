#include <iostream>

//Function prototype (declaration)
unsigned long faculty(const unsigned int number);

int main()
{
	int number;
	do
	{
		std::cout << "Faculty Calculator. Please enter a number >= 0: ";
		std::cin >> number;
	} while (number < 0);

	std::cout << "Result: " << faculty(number) << '\n'; //Call

	//Alternatively with clipboard of the result:
	const unsigned long res = faculty(number);
	std::cout << "Result: " << res << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}

//Function implementation (definition)
unsigned long faculty(const unsigned int number)
{
	unsigned long fac = 1;
	for (unsigned int i = 2; i <= number; ++i)
		fac *= i;
	return fac;
}