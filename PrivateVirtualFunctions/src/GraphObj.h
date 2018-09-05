#pragma once

#include "Place.h"

class GraphObj
{
public:
	explicit GraphObj(const Place& place) //General constructor
		: m_referenceCoordinates{place}
	{}

	virtual ~GraphObj() = default; //Virtual destructor
	GraphObj(const GraphObj&) = default; //Rule of five
	GraphObj(GraphObj&&) = default; //Rule of five
	GraphObj& operator=(const GraphObj&) = default; //Rule of five
	GraphObj& operator=(GraphObj&&) = default; //Rule of five

	//Determine reference point
	const Place& referencePoint() const { return m_referenceCoordinates; }

	//Determine the old reference point and at the same time choose a new one
	Place referencePoint(const Place& p)
	{
		const Place temp{ m_referenceCoordinates };
		m_referenceCoordinates = p;

		return temp;
	}

	//Coordinates search
	int getX() const { return m_referenceCoordinates.getX(); }
	int getY() const { return m_referenceCoordinates.getY(); }

	virtual double area() const //The new interface
	{
		return area_impl(); //Polymorphic call of implementation
	}

	virtual void draw() const //The new interface
	{
		//Check preconditions here if necessary
		draw_impl(); //Polymorphic call of the implementation here check post-conditions if necessary
	}

	//Purely virtual methods
protected:
	virtual void draw_impl() const = 0;

private:
	virtual double area_impl() const = 0;
	Place m_referenceCoordinates;
};

//Standard implementation of a purely virtual method
inline void GraphObj::draw_impl() const { std::cout << "Draw: "; }

//The distance between 2 GraphObj objects is defined here as the distance of their reference points (overloaded function).
inline double distance(const GraphObj& g1, const GraphObj& g2)
{
	return distance(g1.referencePoint(), g2.referencePoint());
}