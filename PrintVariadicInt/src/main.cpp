#include <iostream>

void PrintInt()
{
	std::cout << '\n';
}

template<typename T, typename... Rest>
void PrintInt(T&& obj, Rest&&... rest)
{
	std::cout << obj << ' ';
	PrintInt(rest...);
}

template<typename... Args>
void f1(Args&&... args)
{
	PrintInt(args...); //Expansion p1, p2, p3
}

template<typename... Args>
void f2(Args&&... args)
{
	PrintInt(++args...); //Expansion ++p1, ++p2, ++p3
}

int main()
{
	f1(1, 2, 3); //1 2 3
	f2(1, 2, 3); //2 3 4

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}