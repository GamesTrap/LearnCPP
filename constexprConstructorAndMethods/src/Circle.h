#pragma once

#include <iostream>

template <typename T> 
constexpr T PI = static_cast<T>(3.14159265358979323846264338328L);

class Circle
{
public:
	explicit constexpr Circle(const double r)
		: m_radius(r)
	{
		if (m_radius < 0)
		{
			std::cerr << "Error: negative radius" << std::endl;
			//exit(1);
		}
	}

	constexpr double getRadius() const { return m_radius; }
	constexpr double getArea() const { return m_radius * m_radius * PI<double>; }

	constexpr void setRadius(const double r) { m_radius = r; }

private:
	double m_radius;
};

constexpr Circle scale(const Circle& c, const double factor)
{
	Circle temp = c;
	temp.setRadius(c.getRadius() * factor);
	return temp;
}