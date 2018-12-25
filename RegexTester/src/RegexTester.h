#pragma once

#include <regex>
#include <string>

class RegexTester
{
public:
	RegexTester(const std::string& regEx, const std::string& testStr);

	void Run();

private:
	std::regex m_rgx;
	std::string m_rgxString;
	std::string m_testString;
};