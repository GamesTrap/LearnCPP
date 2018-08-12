#include <iostream>

void move(const unsigned int number, const unsigned int source, const unsigned int target, const unsigned int temp)
{
	if(number > 0) //Termination condition: n == 0
	{
		move(number - 1, source, temp, target); //Recursive call
		std::cout << "Bring a slice of " << source << " to " << target << '\n';
		move(number - 1, temp, target, source); //Recursive call
	}
}

int main()
{
	std::cout << "Towers of Hanoi!" << '\n';
	std::cout << "Please enter number of slices: ";
	unsigned int slices;
	//Better not enter 64, but a smaller number, for example 4.
	std::cin >> slices;
	move(slices, 1, 2, 3);

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}