#include <iostream>
#include "PersonnelAdministration.h"

int main()
{
	PersonnelAdministration personnelAdministration("data.txt");

	std::cout << "Read names and personnel numbers:" << '\n';
	personnelAdministration.output();

	personnelAdministration.dialog();
	std::cout << "End of program" << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}
