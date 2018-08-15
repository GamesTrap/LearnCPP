#pragma once

class Place
{
public:
	int getX() const;
	int getY() const;

	void change(int x, int y); //x, y = new values

private:
	int m_xCoordinate = 0;
	int m_yCoordinate = 0;
};
