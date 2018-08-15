#include <iostream>

#include "Rational.h"

namespace //All 4 operations for a and b
{
	void printTest(const Rational a, const Rational b)
	{
		std::cout << "a = ";
		output(a);
		std::cout << "b = ";
		output(b);
		Rational res = add(a, b);
		std::cout << "+ : ";
		output(res);
		res = sub(a, b);
		std::cout << "- : ";
		output(res);
		res = mult(a, b);
		std::cout << "* : ";
		output(res);
		res = div(a, b);
		std::cout << "/ : ";
		output(res);
		std::cout << '\n';
	}
}

int main()
{
	std::cout << "Please enter a numerator and denominator of the 1. number seperated by spaces: ";
	Rational a;
	input(a);
	std::cout << "Please enter a numerator and denominator of the 2. number seperated by spaces: ";
	Rational b;
	input(b);
	printTest(a, b);

	std::cout << '\n' << "Test with different signs" << '\n';
	a.set(3, 7);
	b.set(6, 13);
	printTest(a, b);
	a.set(3, -7);
	printTest(a, b);
	//... and so on

	std::cout << '\n' << "Test with mixed data types" << '\n';
	a.set(2301, 77777);
	printTest(a, 17);
	printTest(17, a);
	//... and so on

	std::cout << '\n' << "Tet with zero values" << '\n';
	a.set(0, 7);
	b.set(6, 13);
	printTest(a, b);
	//std::cout << "With a denominator = 0 an error is provoked!" << '\n';
	//a.set(3, 0);
	//printTest(a, b);
	//... and so on

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}