#include <iostream>

#include <vector>

int main()
{
	std::vector<int> data; //Initial size is 0
	std::cout << "Please enter values:" << '\n';

	int value;
	do
	{
		std::cout << "Value (0 = end of input): ";
		std::cin >> value;

		if (value != 0)
			data.push_back(value);
	} while (value != 0);

	std::cout << "The following values have been entered:" << '\n';
	for (std::size_t i = 0; i < data.size(); ++i)
		std::cout << i << ". Value: " << data[i] << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}