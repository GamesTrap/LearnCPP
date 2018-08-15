#include <iostream>

#include "Circle.h"

int main()
{
	constexpr Circle cc(100.0); //const and constexpr
	constexpr double cr = cc.getRadius();
	constexpr double ca = cc.getArea();
	std::cout << "Radius = " << cr << ". Area = " << ca << '\n';

	const Circle c(10.0); //const
	const double r = c.getRadius();
	const double a = c.getArea();
	std::cout << "Radius = " << r << ". Area = " << a << '\n';

	Circle c1(210.0); //Not const
	c1.setRadius(9.07);
	std::cout << "Radius = " << c1.getRadius() << ". Area = " << c1.getArea() << '\n';

	constexpr Circle scaled = scale(cc, 0.5);
	std::cout << "Radius = " << scaled.getRadius() << ". Area = " << scaled.getArea() << '\n';

	const Circle scaled1 = scale(c, 0.5);
	std::cout << "Radius = " << scaled1.getRadius() << ". Area = " << scaled1.getArea() << '\n';

	//Provoke with a negative radius error:
	Circle wrong1(-3.0); //Error message at runtime
	//constexpr Circle wrong2(-3.0); //Error message about compilation time

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}
