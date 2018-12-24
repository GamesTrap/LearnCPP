#include <iostream>

void Print()
{
	std::cout << '\n';
}

template<typename T, typename... Rest>
void Print(T&& obj, Rest&&... rest)
{
	std::cout << obj << ' ';
	//Extension beginning
	std::cout << " [" << sizeof...(Rest) << " Type-Parameter(s)] ";
	std::cout << " [" << sizeof...(Rest) << " Function-Parameter(s)]" << '\n';
	//Extension ending
	Print(rest...);
}

int main()
{
	Print(1);
	Print(2, "Hello");
	Print("Text", 7.978353, 3);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}