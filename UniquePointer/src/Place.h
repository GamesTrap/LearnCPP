#pragma once
#include <string>

class Place
{
public:
	//Type conversion constructor. Format: 2 sequences of numbers
	explicit Place(const std::string& str);
	explicit Place(int x = 0, int y = 0);

	int getX() const;
	int getY() const;

	void change(int x, int y);

private:
	int m_xCoordinate;
	int m_yCoordinate;
};

//Global functions
//Calculation of the distance between two places
auto distance(Place place1, Place place2);

//Display on the standard output
void display(Place p);

//Equality operator
bool operator==(Place place1, Place place2);

//Overloading the output operator to output a location
std::ostream& operator<<(std::ostream& os, Place place);