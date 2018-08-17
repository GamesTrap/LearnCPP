#include <iostream>

#include <fstream>
#include <array>

int main()
{
	constexpr int ROWS{ 10 };
	constexpr int COLUMNS{ 8 };

	std::array<std::array<double, COLUMNS>, ROWS> matrix;

	//Fill matrix with values
	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COLUMNS; ++j)
			//matrix[i][j] = i + 1 + (j + 1) / 1000.0;
			matrix.at(i).at(j) = i + 1 + (j + 1) / 1000.0;

	//Write as ASCII file (readable with editor)
	std::ofstream target("matrix.asc");
	if(!target)
	{
		std::cerr << "File could not be opened!" << std::endl;
		//exit(-1);
	}

	//Formatted writing
	for (auto& i : matrix)
	{
		for (double j : i)
		{
			target.width(8);
			target << j;
		}
		target << '\n';
	}

	//Close file to reuse target:
	target.close();

	//Write as a binary file
	target.open("matrix.bin", std::ios::binary);
	if(!target)
	{
		std::cerr << "File could not be opened!" << '\n';
		//exit(-1);
	}
	target.write(reinterpret_cast<const char*>(matrix.data()), sizeof(matrix));

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
} //Automatic close()