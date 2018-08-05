#include <iostream>
#include <string>

int main() //Program with typical string operations
{
	//Create std::string object string and initialize it with "hello".
	//string can be any name
	std::string string("hello");

	//Output string
	std::cout << string << '\n';

	//The vector would instead require a loop for the output, such as the following:

	//Output string by character, unchecked access like vector:
	for (std::size_t i = 0; i < string.size(); ++i)
		std::cout << string[i];
	std::cout << '\n';

	//Output string character by character with index check.
	//The number of character for std::string can also be determined with length().
	for (std::size_t i = 0; i < string.length(); ++i)
		std::cout << string.at(i);
	std::cout << '\n';

	//The test happens like the vector.
	//An attempt to query string.at(i) with i >= string.size() causes a program abort with an error message.

	//Create a copy of the std::string string
	std::string copy(string);
	std::cout << copy << '\n'; //hello

	//Copy by assignment
	std::string strNew{ "new!" };
	copy = strNew;
	std::cout << copy << '\n'; //new!

	//Assignment of a string in quotation marks
	copy = "Letters";
	std::cout << copy << '\n'; //Letters

	//Assign only one character of type char
	string = 'X';
	std::cout << string << '\n'; //X

	//Concatenate std::strings using the += operator
	string += copy;
	std::cout << string << '\n'; //XLetters

	//Concatenate std::strings using the + operator
	string = copy + " ABC";
	std::cout << string << '\n'; //Letters ABC

	string = "123" + copy;
	std::cout << string << '\n'; //123Letters

	//string = "123" + "ABC"; //Doesnt work!
	string = std::string("123") + "ABC"; //OK!

	//Comparison of std::strings
	std::string a{ "Albert" };
	std::string z{ "Alberta" };
	std::string b{ a };

	if (a == b)
		std::cout << a << " == " << b << '\n';
	else
		std::cout << a << " != " << b << '\n';

	if (a < z)
		std::cout << a << " < " << z << '\n';
	if (z > a)
		std::cout << z << " > " << a << '\n';
	if (z != a)
		std::cout << z << " != " << a << '\n';

	//std::string with initialization list {'a', 'b', 'c'}
	std::string str{ 'a','b','c' };
	std::cout << "std::string generated with initialization list: " << str << '\n';
	
	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}