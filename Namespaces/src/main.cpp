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

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}