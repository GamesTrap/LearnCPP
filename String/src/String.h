#pragma once

#include <vector>

class String
{
public:
	explicit String(const char* str = ""); //General constructor
	String& assign(const char*); //Assignment of a char *
	const char& at(std::size_t position) const; //Get the sign
	char& at(std::size_t position); //Get the sign
	//Because of the return type reference, the character can be changed.
	auto length() const { return m_data.size() - 1; }; //Number of characters
	auto data() const { return m_data.data(); }; //Return pointer to content
	void swap(String& string) noexcept; //Exchange
	auto begin() const { return m_data.begin(); };
	auto end() const { return m_data.end(); };

private:
	std::vector<char> m_data;
};

void display(std::ostream& os, const String& s);