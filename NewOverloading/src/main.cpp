#include <iostream>

#include "Person.h"

int main()
{
	Person person("Bob"); //Stack object
	std::cout << "Name: " << person.getName() << '\n';
	Person* ptr1{ new Person("Alex") }; //Heap object
	std::cout << "Name: " << ptr1->getName() << '\n';
	delete ptr1; //Delete heap object

	constexpr std::size_t amo{ 2 };
	Person* arr{ new Person[amo] }; //Create dynamic array
	for (std::size_t i = 0; i < amo; ++i)
		std::cout << i << ": " << arr[i].getName() << '\n';
	delete[] arr; //Delete dynamic array
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}