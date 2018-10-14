#pragma once

#include <set>
#include <iostream>

class CountingObject
{
public:
	friend class Guard;
	CountingObject()
	{
		++m_total;
		m_isHeapObject = (1 == m_objects.count(this));
		std::cout << (m_isHeapObject ? "Heap" : "Stack") << "-Object " << this << " created." << '\n';
	}
	virtual ~CountingObject()
	{
		--m_total;
		std::cout << (m_isHeapObject ? "Heap" : "Stack") << "-Object " << this << " destroyed." << '\n';
	}
	CountingObject(const CountingObject&) = default;
	CountingObject(CountingObject&&) = default;
	CountingObject& operator=(const CountingObject&) = default;
	CountingObject& operator=(CountingObject&&) = default;

	static void status()
	{
		std::cout << "There are " << m_total << " object(s), including " << m_objects.size() << " Heap-object(s)" << '\n';
	}
	static void* operator new(const std::size_t size)
	{
		void* ptr = ::operator new(size);
		m_objects.insert(ptr);

		return ptr;
	}
	static void operator delete(void* ptr)
	{
		m_objects.erase(ptr);
		::operator delete(ptr);
	}

private:
	bool m_isHeapObject;
	static std::set<void*> m_objects;
	static int m_total;
};