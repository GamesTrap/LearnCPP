#pragma once

#include "CountingObject.h"
#include <string_view>

class Person : public CountingObject
{
public:
	explicit Person(const std::string_view& n)
		: m_name(n)
	{		
	}
	virtual ~Person()
	{
		std::cout << "Person-Destructor called (" << m_name << ")" << std::endl;
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