#include <iostream>

enum class Colortype { red, yellow, green };

struct Point
{
	int x;
	int y;
	bool isVisible;
	Colortype color;
};

int main()
{
	Point p1{ 100,200,false,Colortype::yellow }; //Direct initialization

	std::cout << "p1.x = " << p1.x << " p1.y = " << p1.y << " p1.isVisible = " << p1.isVisible << " p1.color = " << static_cast<int>(p1.color) << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}