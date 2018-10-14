#pragma once

#include "Object.h"
#include <string_view>

class Person : public Object
{
public:
	explicit Person(const std::string_view& n = "N.N.")
		: m_name{n}
	{
		std::cout << "sizeof name = " << sizeof(m_name) << '\n';
		std::cout << "sizeof *this = " << sizeof(*this) << '\n';
	}
	~Person()
	{
		std::cout << "Person Destructor called (" << m_name << ")" << '\n';
	}
	Person(const Person&) = default;
	Person(Person&&) = default;
	Person& operator=(const Person&) = default;
	Person& operator=(Person&&) = default;

	auto getName() const
	{
		return m_name;
	}

private:
	std::string_view m_name;
};