#include <iostream>

#include <array>

int main()
{
	constexpr unsigned int ROWS = 2;
	constexpr unsigned int COLUMNS = 3;
	//int matrix[ROWS][COLUMNS] = { {1,2,3},{4,5,6} }; //CArray

	std::array<std::array<int, COLUMNS>, ROWS> matrix = { {{1,2,3},{4,5,6}} }; //Modern Array

	for (auto& i : matrix)
		for (int j : i)
			std::cout << j << ' ';
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}