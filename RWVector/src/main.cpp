#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

template<typename T>
void WriteVector(std::string_view filename, const std::vector<T>& v)
{
	std::ofstream dest(filename.data(), std::ios::binary);
	if (!dest)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	dest.write(reinterpret_cast<const char*>(v.data()), v.size() * sizeof(T));
}

template<typename T>
void ReadVector(std::string_view filename, std::vector<T>& v)
{
	std::ifstream source(filename.data(), std::ios::binary);
	if (!source)
		throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
	source.read(reinterpret_cast<char*>(v.data()), v.size() * sizeof(T));
}

int main()
{
	std::string_view filename("binaryData.bin");
	std::vector<double> v1{ 1.27,3.4,5.678,9.01234,100.836 };
	WriteVector(filename, v1); //Write v1
	decltype(v1) v2(v1.size(), 0.0); //Initialize v2 with 0
	ReadVector(filename, v2); //Read v2
	assert(v1 == v2); //Check for equality

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}