#include <iostream>

#include "Person.h"
#include <string>

int main()
{
	Person person("Bob"); //Stack-Object
	std::cout << "Name: " << person.getName() << '\n';
	Person* pAlex = new Person("Alex"); //Heap-Object
	std::cout << "Name: " << pAlex->getName() << '\n';
	delete pAlex; //Delete Heap-Object
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	Person* pPogChamp = new Person("PogChamp"); //Heap-Object
	std::cout << "Name: " << pPogChamp->getName() << '\n';
	delete pPogChamp; //Delete Heap-Object
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	Person* pJennifer = new Person("Jennifer");
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	Person* pKappa = new Person("Kappa");
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	Person* pLUL = new Person("LUL");
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	delete pKappa;
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	Person* pKeepo = new Person("Keepo");
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	std::cout << "Name: " << pLUL->getName() << '\n';
	std::cout << "Name: " << pKeepo->getName() << '\n';
	delete pJennifer;
	delete pLUL;
	delete pKeepo;
	std::cout << "Free Space: " << Person::freeSpace() << '\n';
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}