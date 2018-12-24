#pragma once

#include <iostream>
#include <cstring>

#define STDMOVE //Return std::move() instead of return at op+(,)
#define DEBUG

#ifdef DEBUG
namespace
{
	unsigned int amountNew = 0;
}
#define DEBUGOUTPUT(x) std::cout << #x << ' ' << ++amountNew << std::endl;
#define DEBUGOUTPUT_NEUTRAL(x) std::cout << #x << std::endl;
#else
#define DEBUGOUTPUT(x) //Nothing
#define DEBUGOUTPUT_NEUTRAL(x) //Nothing
#endif

class StringType
{
public:
	StringType(const char*s)
		: m_len{std::strlen(s)}, m_start{new char[m_len + 1]}
	{
		DEBUGOUTPUT(StringType(const char* s) : new)
		std::strcpy(m_start, s);
	}

	StringType(const StringType& s)
		: m_len{s.m_len}, m_start{new char[m_len + 1]}
	{
		DEBUGOUTPUT(StringType(const StringType& s) : new)
		std::strcpy(m_start, s.m_start);
	}

	//New
	StringType(StringType&& s) noexcept //MoveConstructor (resource stealing)
		: m_len{s.m_len}, m_start{s.m_start} //Take over memory
	{
		DEBUGOUTPUT_NEUTRAL(StringType(const StringType&& s) : move)
			s.m_start = nullptr; //Do not forget (destructor)
	}

	~StringType() { delete[] m_start; }

	//Changed: Transfer by const &, otherwise ambiguity
	StringType& operator=(const StringType& s)
	{
		DEBUGOUTPUT_NEUTRAL(= (const&)called)
		StringType tmp(s); //New is counted up here
		swap(tmp);

		return *this;
	}

	//New
	StringType& operator=(StringType&& s) noexcept //Move Assignment operator
	{
		DEBUGOUTPUT_NEUTRAL(= (&&)called(mode))
		delete[] m_start;
		m_start = s.m_start; //Resource stealing
		s.m_start = nullptr;
		m_len = s.m_len;

		return *this;
	}

	StringType& operator+=(const StringType& s)
	{
		char* temp = new char[m_len + s.m_len + 1]; //Procure new space
		DEBUGOUTPUT(operator+=(const StringType& s) : new)
		std::strcpy(temp, m_start); //Copy part 1
		std::strcpy(temp + m_len, s.m_start); //Copy part 2
		delete[] m_start; //Release old space
		m_len += s.m_len; //Update administrative information
		m_start = temp;

		return *this;
	}

	const char* c_str() const { return m_start; } //Return C-String

	StringType& insert(std::size_t pos, const StringType& s) //Insert s before position pos
	{
		char* temp = new char[m_len + s.m_len + 1]; //Procure new space
		DEBUGOUTPUT(insert(std::size_t pos, const StringType& s) : new)
		std::strncpy(temp, m_start, pos); //Copy the first pos characters
		std::strncpy(temp + pos, s.m_start, s.m_len); //Insert s
		std::strcpy(temp + pos + s.m_len, m_start + pos); //Copy rest
		delete[] m_start; //Release old space
		m_start = temp; //Update administrative information
		m_len += s.m_len; //Update administrative information

		return *this;
	}

	void swap(StringType& m) noexcept
	{
		std::swap(m_start, m.m_start);
		std::swap(m_len, m.m_len);
	}

private:
	std::size_t m_len; //Length
	char* m_start; //Pointer to start
};

inline std::ostream& operator<<(std::ostream& os, const StringType& s)
{
	os << s.c_str();

	return os;
}

inline StringType operator+(const StringType& x, const StringType& y)
{
	DEBUGOUTPUT_NEUTRAL(+(const&, const&)called)
	StringType temp(x);
	temp += y;

	return temp;
}

#ifdef STDMOVE
inline StringType operator+(StringType&& x, const StringType& y)
{
	DEBUGOUTPUT_NEUTRAL(Op2 : +(&&, const&)called(move))

	return std::move(x += y);
}

inline StringType operator+(const StringType& x, StringType&& y)
{
	DEBUGOUTPUT_NEUTRAL(Op3 : +(const&, &&)called(move))

	return std::move(y.insert(0, x));
}

inline StringType operator+(StringType&& x, StringType&& y)
{
	DEBUGOUTPUT_NEUTRAL(Op4 : +(&&, &&)called(move))

	return std::move(x += y);
}
#else
inline StringType operator+(StringType&& x, const StringType& y)
{
	DEBUGOUTPUT_NEUTRAL(+(&&, const&)called(move))

	return x += y;
}

inline StringType operator+(const StringType& x, StringType&& y)
{
	DEBUGOUTPUT_NEUTRAL(+(const&, &&)called(move))

	return y.insert(0, x);
}

inline StringType operator+(StringType&& x, StringType&& y)
{
	DEBUGOUTPUT_NEUTRAL(+(&&, &&)called(move))

	return x += y;
}
#endif