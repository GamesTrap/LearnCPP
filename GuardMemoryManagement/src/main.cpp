#include <iostream>
#include "Person.h"

int main()
{
	Person person("Bob");
	std::cout << "Name: " << person.getName() << '\n';
	CountingObject::status();
	Person* ptr1 = new Person("Alex");
	std::cout << "Name: " << ptr1->getName() << '\n';
	CountingObject::status();
	delete ptr1;
	CountingObject::status();
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}