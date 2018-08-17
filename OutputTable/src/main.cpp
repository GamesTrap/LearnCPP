#include <iostream>

#include <array>

void outputTable2D(int (*T)[3], unsigned int n)
{
	//Alternative: void tableOutput(int T[][3], std::size_t n)
	for(unsigned int i = 0; i < n; ++i)
	{
		for(unsigned int j = 0; j < 3; ++j)
			std::cout << T[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';
}

template <typename Fieldtype>
void outputTable2DT(Fieldtype table, const unsigned int rows) //int (*)[3]
{
	constexpr unsigned int COLUMNS = sizeof table[0] / sizeof table[0][0];
	for(unsigned int i = 0; i < rows; ++i)
	{
		for(unsigned int j = 0; j < COLUMNS; ++j)
			std::cout << table[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';
}

template <typename Fieldtype>
void outputTable2DT(Fieldtype& table) //int [2][3]
{
	constexpr unsigned int ROWS = sizeof(Fieldtype) / sizeof(table[0]);
	constexpr unsigned int COLUMNS = sizeof table[0] / sizeof table[0][0];
	for(unsigned int i = 0; i < ROWS; ++i)
	{
		for(unsigned int j = 0; j < COLUMNS; ++j)
			std::cout << table[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';
}

//Alternative:
template <typename Fieldtype, std::size_t ROWS> //int[3], 2
void outputTable2DTx(Fieldtype (&table)[ROWS])
{
	constexpr unsigned int COLUMNS = sizeof table[0] / sizeof table[0][0];
	for(unsigned int i = 0; i < ROWS; ++i)
	{
		for(unsigned int j = 0; j < COLUMNS; ++j)
			std::cout << table[i][j] << ' ';
		std::cout << '\n';
	}
    std::cout << '\n';
}

int main()
{
	int field1[][3] = { {1,2,3},{4,5,6} };

	outputTable2D(field1, 2);
	//Templates
	outputTable2DT(field1, 2);
	outputTable2DT(field1);
	outputTable2DTx(field1);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}