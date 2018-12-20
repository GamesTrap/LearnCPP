#pragma once

#include <iostream>

class A
{
public:
	A(int a)
		: m_a{a}
	{		
	}
	virtual ~A() = default;

	virtual A& assign(const A& rhs)
	{
		std::cout << "virtual A& A::assign(const A&)" << '\n';
		if (typeid(*this) != typeid(rhs))
			throw std::bad_typeid();
		A temp(rhs);
		swap(temp);

		return *this;
	}

	A& operator=(const A& rhs)
	{
		std::cout << "A& operator=(const A& rhs)" << '\n';

		return assign(rhs);
	}

	virtual void output() const
	{
		std::cout << "A.m_a = " << m_a << ' ';
	}

	void swap(A& rhs) noexcept
	{
		std::swap(m_a, rhs.m_a);
	}

	virtual bool operator==(const A& arg) const
	{
		return typeid(*this) == typeid(arg) && m_a == arg.m_a;
	}

private:
	int m_a;
};