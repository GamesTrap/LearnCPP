#include <iostream>

#include "RegexTester.h"

void TestCases()
{
	const std::string testCases[][2] =
	{
		{"^\\D+([0-9]+) \\1", "Summer 2018 2018"},
		{"[a-c]+", "zcbaaxcadey"},
		{"\\t", "contains	Tab"},
		{"[a-c]*", "z"}, //Greedy
		{"[^aeiou]+", "hello"},
		{"/\\*.*\\*/", "xyz /* hello */ abc */ 123"}, //Greedy
		{"/\\*.*?\\*/", "xyz /* hello */ abc */ 123"} //Not greedy
	};

	for(auto testCase : testCases)
	{
		RegexTester rt(testCase[0], testCase[1]);
		rt.Run();
		std::cout << '\n';
	}
}

int main(int argc, char* argv[])
{
	if(3 != argc)
	{
		TestCases();
		std::cout << R"(Usage: RegexTester.exe "regex" "testString")" << '\n' << "otherwise built-in test cases are output." << '\n';
	}
	else
	{
		try
		{
			RegexTester rt(argv[1], argv[2]);
			rt.Run();
		} catch(std::regex_error& re)
		{
			std::cerr << "Error: " << re.what() << '\n';
		}
	}

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}