#pragma once

#include <cmath>

constexpr auto PI = 3.14159;

class Sine
{
public:
	enum class Mode { radians, angle };

	explicit Sine(const Mode m = Mode::radians)
		: m_calculationMethod{m}
	{}

	double operator()(const double arg) const
	{
		double res = 0;

		switch(m_calculationMethod)
		{
		case Mode::radians:
			res = std::sin(arg);
			break;
		case Mode::angle:
			res = std::sin(arg / 180.0 * PI);
			break;
		}

		return res;
	}

private:
	Mode m_calculationMethod;
};