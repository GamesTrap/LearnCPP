#include <iostream>

#include "Rational.h"

//Only addition a and b, rest is missing
void printTest(Rational a, Rational b)
{
	std::cout << "a = ";
	std::cout << a << '\n';
	std::cout << "b = ";
	std::cout << b << '\n';
	std::cout << "+ : ";
	std::cout << (a + b) << '\n';

	if (a == b) //Boolean operator
		std::cout << a << " == " << b << '\n';
	else
		std::cout << a << " != " << b << '\n';

	std::cout << "a += b = ";
	a += b;
	std::cout << a << '\n';
}

int main()
{
	std::cout << "Test of the input operator" << '\n';
	std::cout << "Please enter numerator and denominator of the first number separated by spaces: ";
	Rational a;
	std::cin >> a;
	std::cout << "Please enter numerator and denominator of the second number separated by spaces: ";
	Rational b;
	std::cin >> b;

	printTest(a, b);

	std::cout << '\n' << "Test with different signs" << '\n';
	a.set(3, 7);
	b.set(6, 13);
	printTest(a, b);
	a.set(3, -7);
	printTest(a, b);
	a.set(-3, -7);
	printTest(a, b);
	a.set(-3, -17);
	b.set(-6, -13);
	printTest(a, b);

	std::cout << '\n' << "Test with zero values" << '\n';
	//Denominator = 0 comment out after test
	a.set(0, 7);
	b.set(6, 13);
	printTest(a, b);
	a.set(3, 7);
	b.set(0, 3);
	printTest(a, b);

	std::cout << '\n' << "Test with mixed data types" << '\n';
	a.set(2301, 77777);
	printTest(a, 17);
	printTest(17, a);

	std::cout << '\n' << "Test with mixed data types, Numbers < 0" << '\n';
	printTest(a, -17);
	printTest(-17, a);

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore();
	std::cin.get();
	return 0;
}