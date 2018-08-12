#include <iostream>

void add7(int& number); //int& = Reference to int

int main()
{
	int i{ 0 };
	std::cout << i << " = old value of i" << '\n';
	add7(i); //Syntax as with transfer by value
	std::cout << i << " = new value of i after add7" << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}

void add7(int& number)
{
	number += 7; //Original of the caller is changed!
}