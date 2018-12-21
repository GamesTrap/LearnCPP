#include <iostream>

#include "NumToString.h"

int main()
{
	double xd = 73.1635435363;                      //Output:
	std::cout << NumToString(xd) << '\n';           //73.1635
	std::cout << NumToString(xd, 12) << '\n';       //73.1635
	std::cout << NumToString(xd, 12, 1) << '\n';    //7.3164e+01
	std::cout << NumToString(xd, 12, 1, 3) << '\n'; //7.316e+01
	std::cout << NumToString(xd, 12, 0, 3) << '\n'; //73.164

	int xi = 1234567;
	std::cout << NumToString(xi) << '\n';     //1234567
	std::cout << NumToString(xi, 14) << '\n'; //1234567

	float xf = 1234.567f;
	std::cout << NumToString(xf) << '\n'; //1234.57
	unsigned long xl = 123456789L;
	std::cout << NumToString(xl) << '\n'; //123456789

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}