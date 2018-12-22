#include <iostream>

#define PERFORMANCE

#ifdef PERFORMANCE
#include "MoveString.h"
#else
#include "SimpleString.h"
#endif

int main()
{
	StringType a("a");
	const StringType b("b");
	const StringType c("c");
	std::cout << "Case 1: a = \"Hello\" + b;" << '\n';
	a = "Hello" + b;

	std::cout << '\n' << "Case 2: a = b + \" hello\";" << '\n';
	a = b + " hello";

	std::cout << '\n' << "Case 3: a = StringType(\"good\") + \" day\";" << '\n';
	a = StringType("good") + " day";

	std::cout << '\n' << "Case 4: a = b + c;" << '\n';
	a = b + c;

	std::cout << '\n' << "Case 5: StringType New = b + c;" << '\n';
	StringType New = b + c;

	std::cout << '\n' << "Case 6: New = a + \"one\" + \"two\" + \"three\";" << '\n';
	New = a + "one" + "two" + "three";

	std::cout << '\n' << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';
	std::cout << "c = " << c << '\n';
	std::cout << "New = " << New << '\n';

	std::cout << '\n' << "Case 7: New = a + b + c + New;" << '\n';
	New = a + b + c + New;
	std::cout << '\n' << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';
	std::cout << "c = " << c << '\n';
	std::cout << "New = " << New << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1024, '\n');
	std::cin.get();
	return 0;
}
