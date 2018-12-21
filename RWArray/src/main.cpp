#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cassert>

template<typename T, auto N>
void WriteArray(std::string_view filename, const std::array<T, N>& a)
{
	std::ofstream dest(filename.data(), std::ios::binary);
	if (!dest)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	dest.write(reinterpret_cast<const char*>(a.data()), a.size() * sizeof(T));
}

template<typename T, auto N>
void ReadArray(std::string_view filename, std::array<T, N>& a)
{
	std::ifstream source(filename.data(), std::ios::binary);
	if (!source)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	source.read(reinterpret_cast<char*>(a.data()), a.size() * sizeof(T));
}

int main()
{
	std::string_view filename("binaryData.bin");
	std::array<double, 5> a1{ 1.2,3.4,5.678,9.01234,100.83653 };
	WriteArray(filename, a1); //Write a1
	decltype(a1) a2{}; //Contains 0.0
	ReadArray(filename, a2); //Read a2
	assert(a1 == a2); //Check for equality

	//Also works for matrices, e.g.
	const std::string_view filename1("binaryDataMatrix.bin");
	//2 Dimensional Matrix
	std::array<std::array<double, 3>, 2> am1 = {{ {{1.1,2.2,3.3}}, {{4.4,5.5,6.6}} }};
	WriteArray(filename1, am1); //Write am1
	decltype(am1) am2{}; //Contains 0.0
	ReadArray(filename1, am2); //Read am2
	assert(am1 == am2); //Check for equality

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}