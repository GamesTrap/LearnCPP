#include "Place.h"
#include <cassert>
#include <iostream>

Place::Place(const std::string& str)
{
	std::size_t pos = 0; //Position of a digit in the string str
	for (unsigned int j = 0; j < 2; j++) //For each coordinate
	{
		while (pos < str.size() && !isdigit(str.at(pos))) //Search first digit
			++pos;
		assert(pos < str.size()); //Number found? Cancel if not
		const bool negative = pos > 0 && str.at(pos - 1) == '-'; //Minus sign found?
		//Make number
		int coordinate = 0;
		while(pos < str.size() && isdigit(str.at(pos)))
		{
			//implicit type conversion char -> int
			coordinate = 10 * coordinate + str.at(pos) - '0';
			++pos;
		}
		if (negative)
			coordinate = -coordinate;
		switch(j)
		{
		case 0:
			m_xCoordinate = coordinate;
			break;
		case 1:
			m_yCoordinate = coordinate;
			break;

		default:
			assert(false); //There can not be other values here
		}
	}
}

Place::Place(const int x, const int y)
	: m_xCoordinate{ x }, m_yCoordinate{ y }
{}

int Place::getX() const { return m_xCoordinate; }
int Place::getY() const { return m_yCoordinate; }

void Place::change(const int x, const int y)
{
	m_xCoordinate = x;
	m_yCoordinate = y;
}

//Global functions
//Calculation of the distance between two places
auto distance(Place place1, Place place2)
{
	const double dx = static_cast<double>(place1.getX() - place2.getX());
	const double dy = static_cast<double>(place1.getY() - place2.getY());

	return std::sqrt(dx * dx + dy * dy);
}

//Display on the standard output
void display(Place p)
{
	std::cout << '(' << p.getX() << ", " << p.getY() << ')';
}

//Equality operator
bool operator==(Place place1, Place place2)
{
	return (place1.getX() == place2.getX() && place1.getY() == place2.getY());
}

//Overloading the output operator to output a location
std::ostream& operator<<(std::ostream& os, Place place)
{
	os << " (" << place.getX() << ", " << place.getY() << ')';

	return os;
}