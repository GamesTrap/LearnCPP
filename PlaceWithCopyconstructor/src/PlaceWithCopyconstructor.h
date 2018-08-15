#pragma once

class Place
{
public:
	Place(const int x, const int y);

	Place(const Place& orig); //Copyconstructor

	//Rule of 5
	Place(Place&& place) = default;
	~Place() = default;
	Place& operator=(const Place& place) = default;
	Place& operator=(Place&& place) = default;

	int getX() const;
	int getY() const;

	void change(int x, int y);

private:
	int m_xCoordinate;
	int m_yCoordiante;
};

double distance(const Place& p1, const Place& p2);

void display(const Place& place);