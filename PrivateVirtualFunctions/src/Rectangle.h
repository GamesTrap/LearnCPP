#pragma once

#include "GraphObj.h"

class Rectangle : public GraphObj //Inherit from GraphObj
{
public:
	Rectangle(const Place p, int w, int h)
		: GraphObj{p}, m_width{w}, m_height{h}
	{}

	//Is needed by square
	auto width() const { return m_width; }
	auto height() const { return m_height; }

private:
	//Definition of purely virtual methods
	virtual double area_impl() const override
	{
		return static_cast<double>(m_width) * m_height;
	}

	virtual void draw_impl() const override
	{
		GraphObj::draw_impl();
		std::cout << "Rectangle (w x h = " << m_width << " x " << m_height << "( at this point ";
		display(referencePoint());
		std::cout << '\n';
	}

	int m_width;
	int m_height;
};