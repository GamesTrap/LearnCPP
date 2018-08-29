#pragma once

#include "GraphObj.h"

class Line : public GraphObj //Inherit from GraphObj
{
public:
	//Initialization with initialization list
	Line(const Place p1, Place p2)
		: GraphObj{p1}, m_endpoint{p2} //Initialization of the subObject and the attributes
	{} //Empty code block

	auto length() const { return distance(referencePoint(), m_endpoint); }

	//Definition of purely virtual methods
	virtual double area() const override //
	{
		return 0.0;
	}

	virtual void draw() const override
	{
		GraphObj::draw();
		std::cout << "Line from ";
		display(referencePoint());
		std::cout << " to ";
		display(m_endpoint);
		std::cout << '\n';
	}

private:
	Place m_endpoint; //Additionally: 2nd point of the line (the first is GraphObj::m_referenceCoordinates)
};