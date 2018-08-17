#include <iostream>

#include "Array2D.h"

int main()
{
	Array2D<int> arr(5, 7);
	arr.init(0);
	printArray(arr); //Output with auxiliary function
	for(std::size_t r = 0; r < arr.getRows(); ++r)
	{
		for(std::size_t c = 0; c < arr.getColumns(); ++c)
		{
			arr.at(r, c) = 10 * r + c; //Use, write and ...
			std::cout << arr.at(r, c) << ' '; //read
		}
		std::cout << '\n';
	}
	printArray(arr);

	Array2D<int> arr1(arr); //Copy constructor
	printArray(arr1);
	arr1.init(3); //Reinitialization
	arr.assign(arr1); //Assignment
	printArray(arr);
	const Array2D<double> arrd(3, 4, 99.013); //double array
	printArray(arrd);

	Array2D<std::string> arrs(2, 5, "Hello"); //string array
	printArray(arrs);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}