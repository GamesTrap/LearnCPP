#pragma once

#include "INVALIDDATEEXCEPTION.h"

constexpr bool isLeapYear(const std::size_t year)
{
	return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

constexpr bool isValidDate(const std::size_t day, const std::size_t month, const std::size_t year)
{
	bool result = false;

	if((month >= 1 && month <= 12) && (year > 1582 && year < 2400)) //1582: Beginning of the Gregorian calendar. Plausibility check
	{
		std::size_t lastDayInMonth = 29; //Only February in leap year

		if(month != 2 || !isLeapYear(year)) //else
		{
			constexpr std::size_t dayInMonth[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

			lastDayInMonth = dayInMonth[month - 1];
		}
		result = (day >= 1 && day <= lastDayInMonth);
	}

	return result;
}

class Date
{
public:
	Date(); //Standard constructor
	constexpr Date(const std::size_t d, const std::size_t m, const std::size_t y) //General constructor
		: m_day(d), m_month(m), m_year(y)
	{
		if (!isValidDate(d, m, y))
			throw InvalidDateException(d, m, y);
	}

	constexpr auto day() const { return m_day; }
	constexpr auto month()const { return m_month; }
	constexpr auto year() const { return m_year; }
	constexpr bool isLeapYear() const
	{
		return ::isLeapYear(m_year); //Global function with :: operator
	}

	void set(std::size_t d, std::size_t m, std::size_t y); //Set date
	void current(); //Set system date

	Date& operator++(); //Count up day, prefix
	Date operator++(int); //Count up day, postfix
	//Alternative: replace with method string toString()

	explicit operator std::string() const; //Type conversion operator

	static int dateDifference(const Date& d1, const Date& d2);

private:
	std::size_t m_day{};
	std::size_t m_month{};
	std::size_t m_year{};
};
	
std::ostream& operator<<(std::ostream& out, const Date& date);
bool operator==(const Date& date1, const Date& date2);
bool operator!=(const Date& date1, const Date& date2);
bool operator<(const Date& date1, const Date& date2);