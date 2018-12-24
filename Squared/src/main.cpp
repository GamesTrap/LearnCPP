#include <iostream>

template<int n>
struct Squared
{
	static const int value{ 2 * Squared<n - 1>::value };
};

template<>
struct Squared<0>
{
	static const int value{ 1 };
};

int main()
{
	std::cout << Squared<11>::value << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}