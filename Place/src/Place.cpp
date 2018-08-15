#include "Place.h"

#include <iostream>

int Place::getX() const { return m_xCoordinate; }
int Place::getY() const { return m_yCoordinate; }

void Place::change(const int x, const int y)
{
	m_xCoordinate = x;
	m_yCoordinate = y;

	std::cout << "Place-Object changed! x = " << m_xCoordinate << " y = " << m_yCoordinate << '\n';
}