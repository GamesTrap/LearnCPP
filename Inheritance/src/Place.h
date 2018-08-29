#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <cctype>

class Place
{
public:
	//Type conversion constructor. Format: 2 sequences of numbers
	explicit Place(const std::string& str)
	{
		std::size_t pos = 0; //Position of a digit in the string str
		for (unsigned int j = 0; j < 2; j++) //For each coordinate
		{
			while (pos < str.size() && !std::isdigit(str[pos])) //Search first digit
				++pos;

			assert(pos < str.size()); //Number found? Cancel if not
			const bool negative = pos > 0 && str[pos - 1] == '-'; //Minus sign found?
			//Make number
			int coordinate = 0;
			while(pos < str.size() && std::isdigit(str[pos]))
			{
				//Implicit type conversion char -> int
				coordinate = 10 * coordinate + str[pos] - '0';
				++pos;
			}

			if (negative)
				coordinate = -coordinate;

			switch(j)
			{
			case 0:
				m_xCoordinate = coordinate;
				break;
			case 1:
				m_yCoordinate = coordinate;
				break;

			default:
				assert(false); //There can not be other values here
			}
		}
	}

	explicit Place(const int x = 0, const int y = 0)
		: m_xCoordinate{x}, m_yCoordinate{y}
	{}

	int getX() const { return m_xCoordinate; }
	int getY() const { return m_yCoordinate; }

	void change(const int x, const int y)
	{
		m_xCoordinate = x;
		m_yCoordinate = y;
	}

private:
	int m_xCoordinate;
	int m_yCoordinate;
};

//Global functions
//Calculation of the distance between two places
inline auto distance(Place p1, Place p2)
{
	const auto dx = static_cast<double>(p1.getX() - p2.getX());
	const auto dy = static_cast<double>(p1.getY() - p2.getY());

	return std::sqrt(dx * dx + dy * dy);
}

//Display on the standard output
inline void display(Place p)
{
	std::cout << '(' << p.getX() << ", " << p.getY() << ')';
}

//Equality operator
inline bool operator==(Place p1, Place p2)
{
	return(p1.getX() == p2.getX() && p1.getY() == p2.getY());
}

//Overloading the output operator to output a location
inline std::ostream& operator<<(std::ostream& os, Place p)
{
	os << " (" << p.getX() << ", " << p.getY() << ')';

	return os;
}