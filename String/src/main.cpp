#include <iostream>

#include "String.h"

int main()
{
	String emptyString;
	std::cout << "Empty string. Length = " << emptyString.length() << '\n';

	String string("Hello");
	std::cout << "Hello: Length = " << string.length() << '\n';
	display(std::cout, string);
	std::cout << '\n' << "Character by character:" << '\n';
	for (char i : string)
		std::cout << '*' << i;
	std::cout << '*' << '\n';
	for (auto c : string) 
		std::cout << '_' << c;
	std::cout << '_' << '\n';
	const String secondString = string;
	std::cout << "Assigned String: ";
	display(std::cout, secondString);
	std::cout << '\n';
	std::cout << "Assign a short string (enough space)" << '\n';
	string.assign("ABC");
	const void* address = static_cast<const void*>(string.data());
	std::cout << address << '\n';
	std::cout << "Content: " << string.data() << " Length: " << string.length() << '\n';
	std::cout << "Assign a long string (space must be recaptured)" << '\n';
	string.assign("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::cout << "Content: " << string.data() << " Lenght: " << string.length() << '\n';
	//
	const String shortString("abcd");
	//
	const void* secondAddress = static_cast<const void*>(string.data());
	std::cout << secondAddress << '\n';
	if (address != secondAddress)
		std::cout << "It was procured memory." << '\n';
	else
		std::cout << "It was used existing storage." << '\n';
	string = shortString;
	std::cout << "Content: " << string.data() << " Length: " << string.length() << '\n';
	const void* thirdAddress = static_cast<const void*>(string.data());
	std::cout << thirdAddress << '\n';
	if (thirdAddress != secondAddress)
		std::cout << "It was procured memory." << '\n';
	else
		std::cout << "It was used existing storage." << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}