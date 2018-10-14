#pragma once

#include <iostream>

class Object
{
public:
	virtual ~Object()
	{
		std::cout << "Object Destructor called (" << this << ")" << '\n';
	}
	Object() = default;
	Object(const Object&) = default;
	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;

	static void* operator new(const std::size_t size)
	{
		std::cout << "new called. size = " << size << '\n';

		return ::operator new(size);
	}
	static void operator delete(void* ptr, const std::size_t size)
	{
		std::cout << "delete called. size = " << size << '\n';

		::operator delete(ptr);
	}
	static void* operator new[](const std::size_t size)
	{
		std::cout << "new[] called. size = " << size << '\n';

		return ::operator new[](size);
	}
	static void operator delete[](void* ptr, const std::size_t size)
	{
		std::cout << "delete[] called. size = " << size << '\n';

		::operator delete[](ptr);
	}
};