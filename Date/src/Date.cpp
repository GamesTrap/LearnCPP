#include "Date.h"

#include <ctime>

Date::Date()
{
	current();
}

void Date::set(const std::size_t d, const std::size_t m, const std::size_t y)
{
	if (!isValidDate(d, m, y))
		throw InvalidDateException(d, m, y);

	m_day = d;
	m_month = m;
	m_year = y;
}

void Date::current() //Enter system date
{
	//time_t, time(), tm, localtime() are declared in <ctime>
	time_t now{ time(nullptr) }; //Current time in s since 1.1.1970
	tm timeInfo{};
	localtime_s(&timeInfo, &now); //Pointer to a predefined structure of type tm.
	m_year = static_cast<std::size_t>(timeInfo.tm_year + 1900);
	m_month = static_cast<std::size_t>(timeInfo.tm_mon + 1); //localtime returns 0..11
	m_day = static_cast<std::size_t>(timeInfo.tm_mday);
}

Date& Date::operator++() //Count up day, prefix
{
	++m_day;

	if(!isValidDate(m_day, m_month, m_year)) //Month end reached?
	{
		m_day = 1;

		if(++m_month > 12) //Year end reached?
		{
			m_month = 1;
			++m_year;
		}
	}

	return *this;
}

Date Date::operator++(int) //Count up day, postfix
{
	const Date temp = *this;
	++*this; //Call prefix ++

	return temp;
}

Date::operator std::string() const
{
	std::string temp("mm/dd/yyyy");

	temp.at(0) = static_cast<char>(m_month / 10 + '0');
	temp.at(1) = static_cast<char>(m_month % 10 + '0');
	temp.at(3) = static_cast<char>(m_day / 10 + '0');
	temp.at(4) = static_cast<char>(m_day % 10 + '0');

	std::size_t pos = 9; //Last year's number
	std::size_t y = m_year;

	while(y > 0)
	{
		temp.at(pos) = y % 10 + '0'; //Last digit
		y = y / 10; //Separate last digit
		--pos;
	}

	return temp;
}

int Date::dateDifference(const Date& d1, const Date& d2)
{
	if (d1 == d2)  //Short process with equality
		return 0;

	const bool rightOrder{ d1 < d2 };
	Date earlier{ d1 };
	Date later{ d2 };

	if (!rightOrder) {  //If necessary, swap
		earlier = d2;
		later = d1;
	}

	int difference{ 0 };
	//Attention! not optimized! (daily counting)
	while (earlier != later) {
		++difference;
		++earlier;
	}

	return rightOrder ? difference : -difference;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.month() << '/' << date.day() << '/' << date.year();

	return out;
}

bool operator==(const Date& date1, const Date& date2)
{
	return date1.day() == date2.day() && date1.month() == date2.month() && date1.year() == date2.year();
}

bool operator!=(const Date& date1, const Date& date2)
{
	return !(date1 == date2);
}

bool operator<(const Date& date1, const Date& date2)
{
	return date1.year() < date2.year() || date1.year() == date2.year() && date1.month() < date2.month() || date1.year() == date2.year() && date1.month() == date2.month() && date1.day() < date2.day();
}