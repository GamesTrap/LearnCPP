#include "PlaceWithCopyconstructor.h"

#include <iostream>
#include <cmath>

Place::Place(const int x, const int y)
	: m_xCoordinate(x), m_yCoordiante(y)
{}

Place::Place(const Place& orig) //Copyconstructor
	: m_xCoordinate(orig.m_xCoordinate), m_yCoordiante(orig.m_yCoordiante)
{
	std::cout << "Copyconstructor for (" << m_xCoordinate << ", " << m_yCoordiante << ") called" << '\n';
}

int Place::getX() const { return m_xCoordinate; }
int Place::getY() const { return m_yCoordiante; }

void Place::change(int x, int y)
{
	m_xCoordinate = x;
	m_yCoordiante = y;
}

//Global functions
//Calculation of the distance between two places
double distance(const Place& p1, const Place& p2)
{
	const double dx = static_cast<double>(p1.getX() - p2.getX());
	const double dy = static_cast<double>(p1.getY() - p2.getY());

	return std::sqrt(dx * dx + dy * dy);
}

//Display on the standard output
void display(const Place& place)
{
	std::cout << '(' << place.getX() << ", " << place.getY() << ')';
}