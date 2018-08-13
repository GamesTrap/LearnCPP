#include <iostream>

namespace A
{
	void print() { std::cout << "A::print()" << '\n'; }
	namespace B
	{
		void print() { std::cout << "A::B::print()" << '\n'; }
	}
}

int main()
{
	A::print();
	A::B::print();

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}