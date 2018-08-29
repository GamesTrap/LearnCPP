#pragma once

#include "Place.h"

class GraphObj
{
public:
	explicit GraphObj(Place place) //General constructor
		: m_referenceCoordinates{ place }
	{}

	virtual ~GraphObj() = default; //Virtual destructor
	GraphObj(const GraphObj&) = default; //Rule of five
	GraphObj(GraphObj&& graphObj) = default; //Rule of five
	GraphObj& operator=(const GraphObj&) = default; //Rule of five
	GraphObj& operator=(GraphObj&& graphObj) = default; //Rule of five

	//Determine reference point
	Place referencePoint() const { return m_referenceCoordinates; }

	//Determine the old reference point and at the same time choose a new one
	Place referencePoint(const Place p)
	{
		const Place temp{ m_referenceCoordinates };
		m_referenceCoordinates = p;

		return temp;
	}

	//Coordinates search
	int getX() const { return m_referenceCoordinates.getX(); }
	int getY() const { return m_referenceCoordinates.getY(); }

	//Purely virtual methods
	virtual double area() const = 0;
	virtual void draw()const = 0;

private:
	Place m_referenceCoordinates;
};

//Standard implementation of a purely virtual method
inline void GraphObj::draw() const { std::cout << "Draw: "; }

//The distance between 2 GraphObj objects is defined here as
//the distance of their reference points (overloaded function).
inline double distance(const GraphObj& g1, const GraphObj& g2)
{
	return distance(g1.referencePoint(), g2.referencePoint());
}