#pragma once

#include <cassert>
#include <ostream>

constexpr auto constexprStrlen(const char* str)
{
	std::size_t length = 0;
	while (*str++) { ++length; }

	return length;
}

class StringView
{
public:
	explicit constexpr StringView(const char* str = "")
		: m_pointer(str), m_amount(constexprStrlen(str))
	{}

	constexpr auto at(const std::size_t position) const
	{
		assert(position < m_amount);

		return m_pointer[position];
	}
	constexpr auto length() const { return m_amount; }
	constexpr auto data() const { return m_pointer; }
	constexpr auto begin() const { return m_pointer; }
	constexpr auto end() const { return m_pointer + m_amount; }

private:
	const char* m_pointer;
	std::size_t m_amount;
};

inline void display(std::ostream& os, StringView stringView)
{
	os << stringView.data();
}