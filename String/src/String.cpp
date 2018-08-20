#include "String.h"

#include <cassert>
#include <string>
#include <iostream>

//The general constructor creates a String object from a classic C string.
String::String(const char* str) //General constructor
	: m_data(std::strlen(str) + 1)
{
	m_data.assign(str, str + m_data.size());
}
String& String::assign(const char* str) //Assignment of a char*
{
	std::size_t newLength = std::strlen(str) + 1;
	if(length() >= newLength) //Enough space available
	{
		m_data.assign(str, str + newLength); //Assign
		m_data.resize(newLength); //Adjust length (shorten))
	}
	else
	{
		String temp(str); //Create object of sufficient size
		swap(temp); //Exchange
	}
	return *this;
}
const char& String::at(std::size_t position) const //Get the sign
{
	assert(position < length()); //Read zero byte is not allowed
	return m_data.at(position);
}
char& String::at(std::size_t position) //Get characters by reference
{
	assert(position < length()); //Read zero byte is not allowed
	return m_data.at(position);
}

void String::swap(String& string) noexcept
{
	std::swap(m_data, string.m_data); //Library function
}

//Global function
void display(std::ostream& os, const String& s)
{
	os << s.data();
}