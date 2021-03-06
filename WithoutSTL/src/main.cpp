#include <iostream>

//New typename IteratorType for 'Pointer to const int'
using IteratorType = const int*;

//Prototype algorithm
IteratorType find(IteratorType begin, IteratorType end, int value);

int main()
{
	constexpr int AMOUNT{ 100 };
	int container[AMOUNT]; //Define container
	const IteratorType begin{ container }; //Pointer to start
	//Position AFTER the last element
	const IteratorType end{ container + AMOUNT };

	//Fill container with various values
	for (unsigned int i = 0; i < AMOUNT; ++i)
		container[i] = 2 * i;

	int number{ 0 };
	while(number != -1)
	{
		std::cout << "Enter the number you are looking for (-1 = end): ";
		std::cin >> number;
		if(number != 1) //Continue?
		{
			const IteratorType position = find(begin, end, number);
			if (position != end)
				std::cout << "Found at position " << (position - begin) << '\n';
			else
				std::cout << number << " not found!" << '\n';
		}
	}
		
	return 0;
}

//Implementation
IteratorType find(IteratorType begin, const IteratorType end, const int value)
{
	while (begin != end && *begin != value) //Pointer comparison | Dereferencing and object comparison
		++begin; //Next place

	return begin;
}