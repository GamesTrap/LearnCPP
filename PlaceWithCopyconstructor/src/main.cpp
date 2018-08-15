#include <iostream>

#include "PlaceWithCopyconstructor.h"

namespace
{
	//Function to move the location by dx and dy
	Place movePlace(Place place, const int dx, const int dy)
	{
		place.change(place.getX() + dx, place.getY() + dy);

		return place; //Return of the changed place
	}
}

int main()
{
	const Place place(10, 300);
	const Place movedPlace = movePlace(place, 10, -90); //Allocation
	std::cout << "Old Place: ";
	display(place);
	std::cout << '\n' << "New Place: ";
	display(movedPlace);
	std::cout << '\n';
	const Place newPlace = movePlace(Place(0, 20), 10, -90); //Temporary object
	std::cout << "Place created from temporary object: ";
	display(newPlace);
	std::cout << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}