#include <iostream>

#include "SimpleStack.h"

int main()
{
	//A stack for 100 int numbers
	SimpleStack<int, 100> intStack;
	//Fill stack
	int i = 100;
	while (!intStack.full())
		intStack.push(i++);
	std::cout << "Amount: " << intStack.size() << '\n';

	//Show top element
	std::cout << "Top element: " << intStack.top() << '\n';

	std::cout << "Extract and display all elements:" << '\n';
	while (!intStack.empty())
	{
		i = intStack.top();
		intStack.pop();
		std::cout << i << '\t';
	}
	std::cout << '\n';

	//A stack for 100 double numbers
	SimpleStack<double, 100> doubleStack;
	//Fill stack
	double d{1.00234};
	while (!doubleStack.full())
	{
		d = 1.1 * d;
		doubleStack.push(d);
	}
	std::cout << '\n' << "Amount: " << doubleStack.size() << '\n';

	//doubleStack.push(1099.986); //Error, because stack full

	std::cout << "Top element: " << doubleStack.top() << '\n';

	std::cout << "Take 4 elements of the double stack:" << '\n';
	for (unsigned int j = 0; j < 4; ++j)
	{
		std::cout << doubleStack.top() << '\t';
		doubleStack.pop();
	}
	std::cout << '\n';

	std::cout << "Remaining amount: " << doubleStack.size() << '\n';
	std::cout << "Clear stack" << '\n';
	doubleStack.clear();
	std::cout << "Amount: " << doubleStack.size() << '\n';

	//doubleStack.pop(); //Error, because stack is empty

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}