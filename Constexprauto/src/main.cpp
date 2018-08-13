#include <iostream>

auto faculty0(unsigned int number) //Not constexpr
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

auto getValue() { return 3u; } //Not constexpr

int main()
{
	//const but not constexpr
	const auto res0 = faculty0(3);
	std::cout << "Result = " << res0 << '\n';

	//constexpr function returns non constexpr value
	auto number = 4u; //Not const
	auto res1 = faculty1(number);
	std::cout << "Result = " << res1 << '\n';

	//constexpr function returns non constexpr value
	const auto cNumber1 = getValue(); //Not initialized with constexpr
	auto res2 = faculty1(cNumber1);
	std::cout << "Result = " << res2 << '\n';

	//constexpr function returns constexpr value
	const auto cNumber2 = 3; //3 is literal
	constexpr auto res3 = faculty1(cNumber2);
	std::cout << "Result = " << res3 << '\n';

	//constexpr function returns constexpr value
	constexpr auto res4 = faculty1(3); //3 is literal
	std::cout << "Result = " << res4 << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}