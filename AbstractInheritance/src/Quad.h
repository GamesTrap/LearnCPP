#pragma once

#include "Rectangle.h"

class Quad : public Rectangle
{
public:
	Quad(const Place place, const int side)
		: Rectangle(place, side, side)
	{}

	//Override the virtual method
	virtual void draw() const override
	{
		GraphObj::draw();
		std::cout << "Quad (Side length = " << height() << ") at this point ";
		display(referencePoint());
		std::cout << '\n';
	}
	//The methods referencePoint(), area(), height(), width() are inherited.
};