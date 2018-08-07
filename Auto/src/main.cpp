#include <iostream>

#include <vector>

struct Point
{
	int x;
	int y;
};

int main()
{
	const Point p1{ 100,200 };
	const auto p2 = p1; //p2 is also of the type Point
	std::cout << "p2.x = " << p2.x << " p2.y = " << p2.y << '\n';

	const std::vector<double> v1{ 1.1,2.2,3.3,4.4,5.5 };
	auto v2(v1); //v2 is also of the type std::vector<double>
	for (auto value : v2)
		std::cout << value << ' '; //Display
	std::cout << '\n';
	//With reference
	for (auto& value : v2)
		value *= 2.0; //Double all elements
	for (auto value : v2)
		std::cout << value << ' '; //Display
	std::cout << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.get();
	return 0;
}