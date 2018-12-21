#include "NumToString.h"

#include <sstream>

std::string NumToString(double d, unsigned width, unsigned format, unsigned amountOfDecimalPlaces)
{
	std::ostringstream converter;

	if(format == 0)
	{
		converter.setf(std::ios::fixed, std::ios::floatfield);
		if(amountOfDecimalPlaces > 0)
			converter.setf(std::ios::showpoint);
	}
	else
	{
		if(format == 1)
			converter.setf(std::ios::scientific, std::ios::floatfield);
	}
	if (format == 0 || format == 1)
		converter.precision(amountOfDecimalPlaces);
	if (width > 0)
		converter.width(width);
	converter << d << std::ends; //Insert number and final null character in the stream

	return converter.str();
}

//In the following, only the first parameter is of different types
std::string NumToString(long i, unsigned width)
{
	return NumToString(static_cast<double>(i), width, 0, 0);
}
std::string NumToString(int i, unsigned width)
{
	return NumToString(static_cast<double>(i), width, 0, 0);
}
std::string NumToString(unsigned long i, unsigned width)
{
	return NumToString(static_cast<double>(i), width, 0, 0);
}
std::string NumToString(unsigned i, unsigned width)
{
	return NumToString(static_cast<double>(i), width, 0, 0);
}