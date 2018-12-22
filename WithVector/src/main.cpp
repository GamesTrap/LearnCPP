#include <iostream>
#include <vector>

//Prototype algorithm replaced with template
template<class Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& value)
{
	while (begin != end && *begin != value) //Pointer comparison | Dereferencing and object comparison 
		++begin;

	return begin;
}

int main()
{
	std::vector<int> container(100); //Define container

	//Fill container with various values
	for (unsigned int i = 0; i < container.size(); ++i)
		container[i] = 2 * i;

	int number{ 0 };
	while(number != -1)
	{
		std::cout << "Enter the number you are looking for (-1 = end): ";
		std::cin >> number;
		if(number != -1) //Continue?
		{
			//Use global find() from above
			std::vector<int>::const_iterator position = ::find(container.begin(), container.end(), number);
			if (position != container.end())
				std::cout << "Found at position " << (position - container.begin()) << '\n';
			else
				std::cout << number << " not found!" << '\n';
		}
	}

	return 0;
}