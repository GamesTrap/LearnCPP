#pragma once

#include "GraphObj.h"

class Line : public GraphObj //Inherit from GraphObj
{
public:
	//Initialization with initializer list
	Line(const Place p1, Place p2)
		: GraphObj{p1}, m_endpoint{p2} //Initialization of the SubObject and the attribute
	{}

	double Length() const
	{
		return distance(referencePoint(), m_endpoint);
	}

private:
	Place m_endpoint; //Additionally: 2nd point of the route
	//(The first is GraphObj::Referencecoordinates)
};
