#pragma once

#include "MemoryManagement.h"
#include <iostream>

namespace
{
	bool test{ true };	
}

class Person final //Not derivable, no virtual destructor
{
public:
	using Memory = MemoryManagement<Person, 100>; //Determine space requirements

	explicit Person(const std::string& n = "N.N.")
	{
		n.copy(m_name, sizeof(m_name) - 1);
		if (test)
			std::cout << "Person-Constructor called (" << m_name << ") this = " << this << '\n';
	}
	~Person()
	{
		if (test)
			std::cout << "Person-Destructor called (" << m_name << ") this = " << this << '\n';
	}
	Person(const Person&) = default;
	Person(Person&&) = default;
	Person& operator=(const Person&) = default;
	Person& operator=(Person&&) = default;

	std::string getName() const
	{
		return m_name;
	}

	static void* operator new(const std::size_t size)
	{
		if (test)
			std::cout << "new called. size = " << size << '\n';

		return Memory::getMemory(size);
	}
	static void operator delete(void* ptr)
	{
		if (test)
			std::cout << "delete called. ptr = " << ptr << '\n';

		Memory::freeMemory(ptr);
	}
	static std::size_t freeSpace()
	{
		return Memory::freeSpace();
	}

private:
	char m_name[15]{ 0 };
};