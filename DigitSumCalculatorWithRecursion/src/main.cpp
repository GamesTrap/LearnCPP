#include <iostream>

int digitSum(const long number) //Pass parameters by value (basic data type)
{
	if (number != 0)
	{
		const int lastDigit = number % 10;
		return lastDigit + digitSum(number / 10); //Recursion
	} //Termination condition n == 0
	return 0;
}

int main()
{
	std::cout << "Number: ";
	long number;
	std::cin >> number;
	std::cout << "Digit sum = " << digitSum(number) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}