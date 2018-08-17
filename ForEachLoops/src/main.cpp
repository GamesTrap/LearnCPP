#include <iostream>

#include <vector>

int main()
{
	std::vector<double> vec = { 1.41, 2.72, 3.14159, 4.09 };
	std::string str("A string");

	std::cout << "Classical counting loop:" << '\n';
	for (std::size_t i = 0; i < vec.size(); ++i)
		std::cout << vec.at(i) << '\t';
	std::cout << '\n';
	for (std::size_t i = 0; i < str.length(); ++i)
		std::cout << str.at(i);
	std::cout << '\n';

	std::cout << "vector: Loop short forms:" << '\n';
	for (double value : vec) //Copy, could be changed
		std::cout << value << '\t';
	std::cout << '\n';
	for (const double value : vec) //Non-changeable copy
		std::cout << value << '\t';
	std::cout << '\n';
	for (double& value : vec) //Reference to change
		value *= 2.0;
	for (const double& value : vec) //Reference to read
		std::cout << value << '\t';
	std::cout << '\n';

	std::cout << "string: Loop short forms:" << '\n';
	for (char character : str) //Copy
		std::cout << character;
	std::cout << '\n';
	for (char& character : str) //Reference to change
		if (character == ' ')
			character = '_';
	for (const char& character : str) //Reference to read
		std::cout << character;

	std::cout << '\n' << '\n' << "With auto:" << '\n';

	std::cout << "vector: Loop short forms:" << '\n';
	for (auto value : vec) //Copy
		std::cout << value << '\t';
	std::cout << '\n';
	for (auto& value : vec) //Reference to change
		value *= 2.0;
	for (const auto& value : vec) //Reference to read
		std::cout << value << '\t';
	std::cout << '\n';

	std::cout << "string: Loop short forms:" << '\n';
	for (auto character : str) //Copy
		std::cout << character;
	std::cout << '\n';
	for (auto& character : str) //Reference to change
		if (character == '_')
			character = ' ';
	for (const auto& character : str) //Reference to read
		std::cout << character;
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
