#include <iostream>

int main()
{
	while(true) //Infinite loop
	{
		char c;
		std::cout << "Please choose: a, b, x = end: ";
		std::cin >> c;

		if(c == 'a')
		{
			std::cout << "Program a" << '\n';
			continue; //back to the selection
		}

		if(c == 'b')
		{
			std::cout << "Program b" << '\n';
			continue; //back to the selection
		}

		if (c == 'x')
			break; //Leave loop

		std::cout << "Wrong input! Please try again!" << '\n';
	}
	std::cout << '\n' << "End of program with break" << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}