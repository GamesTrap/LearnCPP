#pragma once
#include "GraphObj.h"

class Line : public GraphObj //Inherit from GraphObj
{
public:
	//Initialization with initialization list
	Line(const Place& p1, const Place& p2)
		: GraphObj{p1}, m_endPoint{p2} //Initialization of the subObject and attributes
	{} //Empty code block

	double length()const { return distance(referencePoint(), m_endPoint); }

private:
	//Definition of purely virtual methods
	virtual double area_impl() const override
	{
		return 0.0;
	}

	virtual void draw_impl() const override
	{
		GraphObj::draw_impl(); //Call of the standard implementation

		std::cout << "Line from ";
		display(referencePoint());
		std::cout << " to ";
		display(m_endPoint);
		std::cout << '\n';
	}

	Place m_endPoint; //Additionally: 2nd point of the route (the first one is GraphObj::referenceCoordinates)
};