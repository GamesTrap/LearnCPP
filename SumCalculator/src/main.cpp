#include <iostream>

int main()
{
	int summand1, summand2;

	//Read in two numbers
	std::cout << "Please enter two integers: ";
	std::cin >> summand1 >> summand2;

	//Calculate the sum of both numbers
	const int sum = summand1 + summand2;

	//Show the result on the screen
	std::cout << "Sum = " << sum << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}