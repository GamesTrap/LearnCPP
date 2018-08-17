#include <iostream>

unsigned long faculty0(unsigned int number) //Not constexpr
{
	unsigned long fac = 1;
	while (number > 1)
		fac *= number--;

	return fac;
}

constexpr unsigned long faculty1(unsigned int number) //constexpr
{
	return number < 2 ? 1 : number * faculty1(number - 1);
}

unsigned int getValue() { return 3; } //Not constexpr

int main()
{
	//const but not constexpr
	const unsigned long res0 = faculty0(3);
	std::cout << "Result = " << res0 << '\n';

	//constexpr function returns non-constexpr value
	unsigned int number = 4; //Not const
	unsigned long res1 = faculty1(number);
	std::cout << "Result = " << res1 << '\n';

	//constexpr function returns non-constexpr value
	const unsigned int cNumber1 = getValue(); //Not initialized with constexpr
	unsigned long res2 = faculty1(cNumber1);
	std::cout << "Result = " << res2 << '\n';

	//constexpr function returns constexpr value
	const int cNumber2 = 3; //3 is literal
	constexpr unsigned long res3 = faculty1(cNumber2);
	std::cout << "Result = " << res3 << '\n';

	//constexpr function returns constexpr value
	constexpr unsigned long res4 = faculty1(3); //3 is literal
	std::cout << "Result = " << res4 << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}