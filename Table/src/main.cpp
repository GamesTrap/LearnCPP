#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


int main()
{
	std::cout << "Degree    sin(x)      cos(x)" << '\n';
	std::cout.setf(std::ios::showpoint | std::ios::fixed, std::ios::floatfield);
	std::cout.precision(6);

	for(int degree = 0; degree <= 90; degree += 10)
	{
		//Convert degrees to radians
		const double rad = static_cast<double>(degree) / 180.0 * static_cast<double>(M_PI);
		std::cout.width(4);
		std::cout << degree;
		std::cout.width(12);
		std::cout << std::sin(rad);
		std::cout.width(12);
		std::cout << std::cos(rad) << '\n';
	}

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}