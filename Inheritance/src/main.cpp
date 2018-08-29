#include <iostream>

#include "Rectangle.h"
#include "Line.h"

int main()
{
	//Definition of two graphical objects
	const Place nullPoint;
	GraphObj g0(nullPoint);
	Place aPlace(10, 20);
	GraphObj g1(aPlace);

	//Output of both reference points in different ways
	std::cout << "g0.getX() = " << g0.getX() << '\n';
	std::cout << "g0.getY() = " << g0.getY() << '\n';
	Place place = g1.referencePoint();

	std::cout << "place.getX() = " << place.getX() << '\n';
	std::cout << "place.getY() = " << place.getY() << '\n';

	//Output of the distance
	std::cout << "Distance = " << distance(g0, g1) << '\n';

	std::cout << "New reference point for g0:" << '\n';
	g0.referencePoint(place); //Return value is ignored here
	std::cout << "g0.referencePoint() = ";
	display(g0.referencePoint());
	std::cout << '\n' << "Distance = " << distance(g0, g1) << '\n';

	const Place sta;
	Line l1(sta, place);

	std::cout << "Line from ";
	display(sta);
	std::cout << " to ";
	display(place);

	std::cout << '\n' << "Area of line l1 = " << l1.Area() << '\n'; //Inherited method

	std::cout << "Length of line l1 = " << l1.Length() << '\n'; //Additional method

	aPlace = Place(20, 30); //Reassignment
	const Place place2(100, 50);
	Line l2(aPlace, place2);

	std::cout << "Distance of the reference points: " << distance(l1.referencePoint(), l2.referencePoint()) << '\n';

	std::cout << "Distance of the lines l1, l2 = " << distance(static_cast<GraphObj>(l1), static_cast<GraphObj>(l2)) << '\n';
	//...

	Rectangle rect(Place(0, 0), 20, 50);
	std::cout << "rect.Area = " << rect.Area() << '\n'; //1000

	std::cout << rect.GraphObj::Area() << '\n'; //0!

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
