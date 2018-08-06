#include <iostream>

#include <string>

//Working values: V1, V2 
#define V2

int main()
{
#ifdef V1
	std::cout << "Please enter first and last name: ";
	std::string name;
	std::cin >> name;
	std::cout << name << '\n';
#endif

#ifdef V2
	std::cout << "Please enter first and last name: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << name << '\n';
#endif

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}