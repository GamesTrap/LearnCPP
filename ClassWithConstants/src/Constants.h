#pragma once

#include <array>

class Constants
{
public:
	enum Enumeration { null, one, two, three };
	enum class RGB { RED = 0x0001, YELLOW = 0x0002, BLUE = 0x0004 };
	static constexpr double CONST_DOUBLE{ 0.1234 }; //Literals require constexpr.
	static const int CONST_INT{ 1000 }; //For integral literals const.
	static const std::string CONST_STR1; //External initialization
	static inline const std::string CONST_STR2 = "ABC"; //Inline initialization

private:
	inline static std::array<int, 1> m_cArray{ CONST_INT }; //Exemplary internal use
	//...
};
