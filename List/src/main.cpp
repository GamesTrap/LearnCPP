#include <iostream>
#include "List.h"
#include <algorithm>

int main()
{
	List<int> container; //Define container

	//Fill container with various values
	for (int i = 0; i < 100; ++i)
		container.push_front(2 * i);

	int number{ 0 };
	while(number != -1)
	{
		std::cout << "Enter searched number (-1 = end): ";
		std::cin >> number;
		if(number != -1) //Continue?
		{
			//Use std::find()
			auto position = std::find(container.begin(), container.end(), number); //Container methods
			if (position == container.end())
				std::cout << "Not found!" << '\n';
			else
				std::cout << *position << " found!" << '\n'; //Dereferencing of the Iterators
		}
	}

	std::cout << "Output List:" << '\n';
	for (int& iter : container)
		std::cout << iter << '\n';

	std::cin.ignore(1024, '\n');
	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
