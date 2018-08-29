#pragma once

#include <string_view>

class BaseClass
{
public:
	explicit BaseClass(std::string_view identifier)
		: m_attribute{identifier}
	{}

	auto getAttribute() const
	{
		return m_attribute;
	}

private:
	std::string_view m_attribute;
};
