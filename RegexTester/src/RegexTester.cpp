#include "RegexTester.h"

#include <iostream>

RegexTester::RegexTester(const std::string& regEx, const std::string& testStr)
	: m_rgx{regEx}, m_rgxString{regEx}, m_testString{testStr}
{	
}

void RegexTester::Run()
{
	std::sregex_iterator first(m_testString.begin(), m_testString.end(), m_rgx);
	std::sregex_iterator last;
	std::cout << "Regex: " << m_rgxString << "  TestString: " << m_testString << '\n';
	if (first == last)
		std::cout << "nothing found" << '\n';
	else
	{
		while(first != last)
		{
			auto result = *first++; //auto = std::match_results<std::string::const_iterator>
			for(unsigned int i = 0; i < result.size(); ++i)
			{
				if (i > 0)
					std::cout << "Capturing Group " << i << ": ";
				std::cout << "\"" << result.str(i) << "\" found. Position " << result.position(i);
				if (result.length(i) > 1)
					std::cout << " till " << result.position(i) + result.length(i) - 1;
				std::cout << '\n';
			}
		}
	}
}