#include <iostream>

int add5(int x); //Declaration (function prototype)

int main()
{
	const int i{ 0 };
	std::cout << i << " = Value of i" << '\n';
	const auto res = add5(i); //Call
	std::cout << res << " = Result of add_5" << '\n';
	std::cout << i << " = i unchanged!" << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}

int add5(int x) //Definition
{
	x += 5;

	return x;
}