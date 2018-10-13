#pragma once

#include <stdexcept>
#include <string>

class InvalidDateException : public std::runtime_error
{
public:
	InvalidDateException(const std::size_t d, const std::size_t m, const std::size_t y)
		: std::runtime_error(toString(d, m, y))
	{		
	}

private:
	static std::string toString(const std::size_t day, const std::size_t month, const std::size_t year)
	{
		return std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year) + " is an invalid date!";
	}
};
