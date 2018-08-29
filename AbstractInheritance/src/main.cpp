#include <iostream>

#include "Line.h"
#include "Quad.h"
#include <vector>

int main()
{
	//GraphObj g; Error! There are no instances of abstract classes

	Rectangle r(Place(0, 0), 20, 50);
	Line l(Place(1, 20), Place(200, 0));
	Quad q(Place(122, 99), 88);
	//Vector with base class pointers, initialized with the addresses of the objects
	std::vector<GraphObj*> graphObjPointer{ &r, &l, &q };

	//Output of the area of all objects
	for (auto graphObjPtr : graphObjPointer)
		std::cout << "Area = " << graphObjPtr->area() << '\n';
	//Drawing all objects
	for (auto graphObjPtr : graphObjPointer)
		graphObjPtr->draw();

	std::cout << "Also references are polymorphic:" << '\n';
	GraphObj& rRef = r; //The static type is the same,
	GraphObj& lRef = l;
	GraphObj& qRef = q;
	rRef.draw(); //the dynamic is not.
	lRef.draw();
	qRef.draw();

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
