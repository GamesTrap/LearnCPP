#pragma once

#include "Place.h"

class GraphObj
{
public:
	explicit GraphObj(Place place) //General constructor
		: m_referenceCoordinates{place}
	{}

	//Determine reference point
	Place referencePoint() const
	{
		return m_referenceCoordinates;
	}

	//Determine the old reference point and at the same time choose a new one
	Place referencePoint(const Place p)
	{
		const Place tmp{ m_referenceCoordinates };
		m_referenceCoordinates = p;

		return tmp;
	}

	//Coordinates search
	int getX() const
	{
		return m_referenceCoordinates.getX();
	}
	int getY() const
	{
		return m_referenceCoordinates.getY();
	}

	//Standard implementation
	static double Area()
	{
		return 0.0;
	}

private:
	Place m_referenceCoordinates;
};

//The distance between 2 GraphObj objects is defined here as
//the distance of their reference points (overloaded function).
inline double distance(GraphObj g1, GraphObj g2)
{
	return distance(g1.referencePoint(), g2.referencePoint());
}