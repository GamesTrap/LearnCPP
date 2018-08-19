#include <iostream>

#include "Place.h"
#include <vector>

void f(const std::unique_ptr<Place>& up) //By reference!
{
	std::cout << "f() called: " << up->getX() << ' ' << up->getY() << '\n';
}

int main()
{
	{ //New block
		const auto uptr = std::make_unique<Place>(1, 2);
		//Use as pointer
		std::cout << "(x, y) = " << uptr->getX() << ' ' << uptr->getY() << '\n';
		//Use as reference
		std::cout << "(x, y) = " << (*uptr).getX() << ' ' << (*uptr).getY() << '\n';
		//Copy of the place, not the pointer
		Place place = *uptr;
		std::cout << "x = " << place.getX() << '\n';
	} //Block end. Automatic destructor call!

	//Vector
	std::vector<std::unique_ptr<Place>> vec(2); //2 elements
	vec.at(0) = std::make_unique<Place>(3, 4); //Initialize
	vec.at(1) = std::make_unique<Place>(5, 6); //Initialize
	vec.push_back(std::make_unique<Place>(7, 8)); //Now 3 elements
	//Output all:
	for (const auto& placeptr : vec) //Reference!
		std::cout << placeptr->getX() << ' ' << placeptr->getY() << '\n';
	f(vec.at(2)); //Call up function f() defined above

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}