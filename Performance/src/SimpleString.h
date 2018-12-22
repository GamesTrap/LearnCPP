#pragma once

#include <iostream>

#define DEBUG

#ifdef DEBUG
namespace
{
	unsigned int amountNew = 0;
}
#define DEBUGOUTPUT(x) std::cout << #x << ' ' << ++amountNew << std::endl;
#else
#define DEBUGOUTPUT(x) //Nothing
#endif

class StringType
{
public:
	StringType(const char* s) //Constructor
		: m_len{std::strlen(s)}, m_start{new char[m_len + 1]}
	{
		DEBUGOUTPUT(StringType(const char* s) : new)
		std::strcpy(m_start, s);
	}

	StringType(const StringType& s) //CopyConstructor
		: m_len{s.m_len}, m_start{new char[m_len + 1]}
	{
		DEBUGOUTPUT(StringType(const StringType& s) : new)
		std::strcpy(m_start, s.m_start);
	}

	~StringType() //Destructor
	{
		delete[] m_start;
	}

	StringType& operator=(StringType s) //Assignment operator
	{
		swap(s);

		return *this;
	}

	StringType& operator+=(const StringType& s) //Concatenation operator
	{
		DEBUGOUTPUT(operator+=(const StringType& s) : new)
		char* temp{ new char[m_len + s.m_len + 1] }; //Procure new space
		std::strcpy(temp, m_start); //Copy part 1
		std::strcpy(temp + m_len, s.m_start); //Copy part 2
		delete[] m_start; //Release old space
		m_len += s.m_len; //Update administrative information
		m_start = temp;

		return *this;
	}

	const char* c_str() const { return m_start; } //Return C-String

	void swap(StringType& m) noexcept
	//Swap
	{
		std::swap(m_start, m.m_start);
		std::swap(m_len, m.m_len);
	}

private:
	std::size_t m_len; //Length
	char *m_start; //Pointer to m_start
};

//Output operator
inline std::ostream& operator<<(std::ostream &os, const StringType& s)
{
	os << s.c_str();

	return os;
}

//Binary concatenation operator
inline StringType operator+(StringType a, const StringType& b)
{
	return a += b;
}