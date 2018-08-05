#include <iostream>

int main()
{
	std::cout << "Limits for float number types:" << '\n';
	std::cout << "float minimum       = " << std::numeric_limits<float>::min() << '\n';
	std::cout << "float maximum       = " << std::numeric_limits<float>::max() << '\n';
	std::cout << "double minimum      = " << std::numeric_limits<double>::min() << '\n';
	std::cout << "double maximum      = " << std::numeric_limits<double>::max() << '\n';
	std::cout << "long double minimum = " << std::numeric_limits<long double>::min() << '\n';
	std::cout << "long double maximum = " << std::numeric_limits<long double>::max() << '\n';

	std::cout << '\n' << "Number of bytes for:" << '\n';
	std::cout << "float       = " << sizeof(float) << '\n';
	std::cout << "double      = " << sizeof(double) << '\n';
	std::cout << "long double = " << sizeof(long double) << '\n';
	std::cout << "float and double numbers do";
	if constexpr (!std::numeric_limits<float>::is_iec559)
		std::cout << " not";
	std::cout << " comply with the IEC 559 (=IEEE 754) standard." << '\n';

	std::cout << '\n' << "Bits for the mantissa incl. Sign bot:" << '\n';
	std::cout << "float       = " << std::numeric_limits<float>::digits << '\n';
	std::cout << "double      = " << std::numeric_limits<double>::digits << '\n';
	std::cout << "long double = " << std::numeric_limits<long double>::digits << '\n';

	std::cout << '\n' << "Accuracy in decimal places:" << '\n';
	std::cout << "float       = " << std::numeric_limits<float>::digits10 << '\n';
	std::cout << "double      = " << std::numeric_limits<double>::digits10 << '\n';
	std::cout << "long double = " << std::numeric_limits<long double>::digits10 << '\n';

	std::cout << '\n' << "max.Exponent binary and decimal:" << '\n';
	std::cout << "float       = " << std::numeric_limits<float>::max_exponent << '\t';
	std::cout << std::numeric_limits<float>::max_exponent10 << '\n';
	std::cout << "double      = " << std::numeric_limits<double>::max_exponent << '\t';
	std::cout << std::numeric_limits<double>::max_exponent10 << '\n';
	std::cout << "long double = " << std::numeric_limits<long double>::max_exponent << '\t';
	std::cout << std::numeric_limits<long double>::max_exponent10 << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}