#include <iostream>

#include <array>

//Definition of the comparison function
int icmp(const void* a, const void* b)
{
	//Type conversion of pointers to void in pointer to int and subsequent dereferencing (read from right)
	//The type conversion means that the memory contents pointed to by a and b are to be interpreted as int.
	const int ia(*static_cast<const int*>(a));
	const int ib(*static_cast<const int*>(b));

	//Comparison and result return (> 0, = 0, or <0)
	if (ia == ib)
		return 0;
	return ia > ib ? 1 : -1;
}

int main()
{
	std::array<int, 10> ifield{ 100,22,3,44,6,9,2,1,8,9 };
	constexpr auto numberOfElements = std::size(ifield);
	qsort(ifield.data(), numberOfElements, sizeof(ifield.at(0)), icmp); //Sort
	for (int i : ifield) //Output of the sorted field
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}