#pragma once

#include "BaseClass.h"

class DerivedClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Inherit BaseClass constructors

	DerivedClass(const std::string_view ide, const int no)
		: BaseClass{ide}, m_value{no}
	{}

	auto getValue()const
	{
		return m_value;
	}

private:
	int m_value{ 99 }; //Initialization
};
