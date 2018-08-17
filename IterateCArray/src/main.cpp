#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> carray{0,1,2,3,4,5,6,7,8,9};
	auto start = std::begin(carray);
	while (start != std::end(carray))
		std::cout << *start++ << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
