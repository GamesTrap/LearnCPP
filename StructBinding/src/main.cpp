#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	Point p1{ 100,200 };
	auto[a, b] = p1; //Copy
	std::cout << "a = " << a << " b = " << b << '\n';
	auto&[c, d] = p1; //Reference
	c += 50; //Changes p1.x
	d += 50; //Changes p1.y
	std::cout << "p1.x = " << p1.x << " p1.y = " << p1.y << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.get();
	return 0;
}