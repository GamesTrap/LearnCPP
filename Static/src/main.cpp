#include <iostream>

void func() //Counts the number of calls
{
	static int amount{ 0 };
	std::cout << "Amount = " << ++amount << '\n';
}

int main()
{
	for (int i = 0; i < 3; ++i)
		func();

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}