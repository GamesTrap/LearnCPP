#include <iostream>

#include "NumberSequence.h"

int main()
{
	NumberSequence n0;
	n0.print();
	NumberSequence n1{};
	n1.print();
	NumberSequence n2{ 1 };
	n2.print();
	NumberSequence n3{ 2,3 };
	n3.print();
	NumberSequence n3a(2, 3);
	n3a.print();
	NumberSequence n4{ 4,5,6 };
	n4.print();
	NumberSequence n5{ {7,8,9} };
	n5.print();

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}