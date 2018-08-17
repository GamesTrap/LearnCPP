#include <iostream>

double maximum(double x, double y)
{
	return x > y ? x : y; //Conditional operator
}

//Second function of the same name but different signature
int maximum(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	const double a = 100.2;
	const double b = 333.777;
	const int c = 1700;
	const int d = 1000;

	std::cout << maximum(a, b) << '\n'; //Call of maximum(double x, double y)
	std::cout << maximum(c, d) << '\n'; //Call of maximum(int x, int y)

	constexpr float E{ 2.7182f };
	constexpr float PI{ 3.14159f };

	std::cout << maximum(E, PI) << '\n';
	std::cout << maximum(31, 'A') << '\n';

	std::cout << maximum(3.1, static_cast<float>(7)) << '\n';
	std::cout << maximum(3.1, static_cast<double>(7)) << '\n';

	const int x = 66;
	const char y = static_cast<char>(x);

	std::cout << maximum(static_cast<int>(0.1), static_cast<int>(y)) << '\n';
	//Prerequisite: char is signed char.
	//maximum(int x, int y) gets called.
	std::cout << maximum(-1000, static_cast<char>(600)) << '\n'; //Results 88
	std::cout << maximum(-1000, static_cast<char>(128)) << '\n'; //Results -128
	std::cout << maximum(-1000, static_cast<char>(129)) << '\n'; //Results -127 and so on

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}