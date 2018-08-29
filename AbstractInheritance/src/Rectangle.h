#pragma once

#include "GraphObj.h"

class Rectangle : public GraphObj //Inherit from GraphObj
{
public:
	Rectangle(const Place place, const int w, const int h)
		: GraphObj{ place }, m_width{w}, m_height{h}
	{}

	//Is needed by Quad
	auto width() const { return m_width; }
	auto height() const { return m_height; }

	//Definition of purely virtual methods
	virtual double area() const override
	{
		return static_cast<double>(m_width) * m_height;
	}

	virtual void draw() const override
	{
		GraphObj::draw();
		std::cout << "Rectangle (w x h = " << m_width << " x " << m_height << ") at this point ";
		display(referencePoint());
		std::cout << '\n';
	}

private:
	int m_width;
	int m_height;
};