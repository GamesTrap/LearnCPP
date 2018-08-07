#include <iostream>

union IntFloat
{
	int intNumber;
	float floatNumber;
};

union Union2
{
	int value;
	IntFloat intFloat;
};

int main()
{
	IntFloat aUnion{};
	aUnion.intNumber = 42; //Use memory space
	std::cout << aUnion.intNumber << '\n'; //Use saved value
	aUnion.floatNumber = 0.987f; //Occupy the same memory space
	std::cout << aUnion.floatNumber << '\n'; //... and use

	//Output of the addresses
	std::cout << &aUnion.intNumber << '\n' << &aUnion.floatNumber << '\n'; //must be the same

	//Error: Abuse for typecasting
	std::cout << aUnion.intNumber << '\n'; //Interpretation of a float bit pattern as an int number

	//Common of the same types in the beginning (only int)
	Union2 u2{};
	u2.value = 99;
	std::cout << u2.intFloat.intNumber << '\n'; //OK

	std::cout << "Press any key to continue . . . ";
	std::cin.get();
	return 0;
}