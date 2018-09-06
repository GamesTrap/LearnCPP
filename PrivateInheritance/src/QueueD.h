#pragma once

#include <list>

template <typename T>
class Queue //With delegation to a list object (attribute list)
{
public:
	bool empty() const { return m_list.empty(); }
	auto size() const { return m_list.size(); }
	void push(const T& x) //Insert at the end
	{
		m_list.push_back(x);
	}
	void pop() //At the beginning
	{
		m_list.pop_front();
	}
	const T& front() const //Read in the beginning
	{
		return m_list.front();
	}
	const T& back() const //Read in the end
	{
		return m_list.back();
	}

private:
	std::list<T> m_list;
};