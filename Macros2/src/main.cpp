#include <iostream>

int main()
{
	std::cout << "__FILE_ (File): " << __FILE__ << '\n'
		<< "__LINE__ (Line): " << __LINE__ << '\n'
		<< "__func__ (Function): " << __func__ << '\n'
		<< "__DATE__ (Date of compilation): " << __DATE__ << '\n'
		<< "__TIME__ (Time of compilation): " << __TIME__ << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}