#pragma once

#include "Rectangle.h"

class Square : public Rectangle
{
public:
	Square(const Place& p, int side)
		: Rectangle(p, side, side)
	{}

private:
	//Draw the definition of the purely virtual method
	virtual void draw_impl() const override
	{
		GraphObj::draw_impl(); //Call of the standard implementation

		std::cout << "Quad (Side length = " << height() << ") at this point ";
		display(referencePoint());
		std::cout << '\n';
	}
	//The methods referencePoint(), area(), height(), width() are inherited.
};