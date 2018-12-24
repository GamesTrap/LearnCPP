#include <iostream>

constexpr auto lambdaFunction = [](const int a, const int b)
{
	return a + b;
};

int(*functionPointer)(int, int) = lambdaFunction;
//or int(*functionPointer)(int, int) = [](const int a, const int b) { return a + b; };

int main()
{
	//Call with Lambda-Function
	std::cout << lambdaFunction(1, 99) << '\n'; //100
	//Call over Function-Pointer
	std::cout << functionPointer(1, 99) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}