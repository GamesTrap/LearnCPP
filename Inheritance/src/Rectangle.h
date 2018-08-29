#pragma once

#include "GraphObj.h"

class Rectangle : public GraphObj //Inherit from GraphObj
{
public:
	Rectangle(const Place place, const int w, int h)
		: GraphObj{place}, m_width{w}, m_height{w}
	{}

	double Area() const
	{
		//Avoid int overflow
		return static_cast<double>(m_width) * m_height;
	}

private:
	int m_width;
	int m_height;
};
