#include "This.h"

int This::get() const { return m_value; }

//Adding v to the attribute value
This& This::add(const int v) //Return by reference!
{
	m_value += v;
	return *this; //Return the object
}

//Assignment of t (replacement for =-Operator)
This& This::assign(const This& t) //Return by reference!
{
	m_value = t.m_value;
	return *this;
}