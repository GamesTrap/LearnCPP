#pragma once

#include "A.h"

class B : public A
{
public:
	B(const int a, const int b)
		: A(a), m_b{b} //Upper class constructor, local data
	{		
	}

	B& assign(const A& rhs) override
	{
		std::cout << "virtual B& B::assign=(const A&)" << '\n';
		if (typeid(*this) != typeid(rhs))
			throw std::bad_typeid();
		B temp(dynamic_cast<const B&>(rhs));
		swap(temp);

		return *this;
	}

	B& operator=(const B& rhs)
	{
		std::cout << "B& operator=(const B& rhs)" << '\n';

		return assign(rhs);
	}

	void output() const override
	{
		A::output();
		std::cout << "B.m_b = " << m_b << ' ';
	}

	void swap(B& rhs) noexcept
	{
		A::swap(rhs); //Upper class data
		std::swap(m_b, rhs.m_b); //Local data
	}

	bool operator==(const A& arg) const override
	{
		return A::operator==(arg) && m_b == dynamic_cast<const B&>(arg).m_b;
	}

private:
	int m_b;
};
