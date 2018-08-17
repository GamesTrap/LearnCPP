#include <iostream>

#include "Place.h" //Read in the definition of the class

int main()
{
	Place place; //Create object
	place.change(100, 200);
	std::cout << "The place has the coordinates x = " << place.getX() << " and y = " << place.getY() << '\n';
	const Place cPlace = place; //const object
	const int x = cPlace.getX();
	std::cout << x << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}