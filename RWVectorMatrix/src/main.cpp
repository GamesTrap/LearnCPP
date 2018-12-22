#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

template<typename T>
using Matrix = std::vector<std::vector<T>>; //Shortcut

template<typename T>
void WriteVectorMatrix(std::string_view filename, const Matrix<T>& matrix)
{
	std::ofstream dest(filename.data(), std::ios::binary);
	if (!dest)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	for (const auto& line : matrix) //Write line by line
		dest.write(reinterpret_cast<const char*>(line.data()), line.size() * sizeof(T));
}

template<typename T>
void ReadVectorMatrix(std::string_view filename, Matrix<T>& matrix)
{
	std::ifstream source(filename.data(), std::ios::binary);
	if (!source)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	for (auto& line : matrix) //Read line by line
		source.read(reinterpret_cast<char*>(line.data()), line.size() * sizeof(T));
}

int main()
{
	std::string_view filename("binaryDataMatrix.bin");
	Matrix<double> mat1 = {{ {{1.1, 2.2, 3.3}}, {{4.4, 5.5, 6.6}} }};
	WriteVectorMatrix(filename, mat1); //Write mat1
	//Create new matrix mat2 in the right size:
	Matrix<double> mat2(mat1.size(), std::vector<double>(mat1[0].size())); //Contains 0.0
	ReadVectorMatrix(filename, mat2); //Read mat2
	assert(mat1 == mat2); //Check for equality

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}