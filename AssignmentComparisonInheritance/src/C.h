#pragma once

#include "B.h"

class C : public B
{
public:
	C(int a, int b, int c)
		: B(a, b), m_c{ c } //Upper class subobject, local data
	{
	}

	C& assign(const A& rhs) override
	{
		std::cout << "virtual C& C::assign=(const A&)" << '\n';
		if (typeid(*this) != typeid(rhs))
			throw std::bad_typeid();
		C temp(dynamic_cast<const C&>(rhs));
		swap(temp);

		return *this;
	}

	C& operator=(const C& rhs)
	{
		std::cout << "C& operator=(const C& rhs)" << '\n';

		return assign(rhs);
	}

	void output() const override
	{
		B::output();
		std::cout << "C.m_c = " << m_c << ' ';
	}

	void swap(C& rhs) noexcept
	{
		B::swap(rhs); //Upper class data
		std::swap(m_c, rhs.m_c); //Local data
	}

private:
	int m_c;
};