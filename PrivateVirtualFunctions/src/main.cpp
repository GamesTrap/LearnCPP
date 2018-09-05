#include <iostream>

#include "Square.h"
#include "Line.h"
#include <vector>

int main()
{
	//GraphObj g; Error!
	//There are no instances of abstract classes.

	Rectangle r(Place(0, 0), 20, 50);
	Line l(Place(1, 20), Place(200, 0));
	Square s(Place(112, 99), 88);

	//Vector with base class pointers, initialized with the addresses of the objects
	std::vector<GraphObj*> graphObjPointer{ &r, &l, &s };

	//Output of the area of all objects
	for (auto graphObjPtr : graphObjPointer)
		std::cout << "Area = " << graphObjPtr->area() << '\n';
	//Drawing all objects
	for (auto graphObjPtr : graphObjPointer)
		graphObjPtr->draw();
	std::cout << "Also references are polymorphic:" << '\n';
	GraphObj& r_ref = r; //The static type is the same,
	GraphObj& l_ref = l;
	GraphObj& s_ref = s;
	r_ref.draw(); //The dynamic is not.
	l_ref.draw();
	s_ref.draw();

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}