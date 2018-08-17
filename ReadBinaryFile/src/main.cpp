#include <iostream>

#include <fstream>

int main()
{
	std::ifstream source("double.dat", std::ios::binary);
	if(!source) //Must exist
	{
		std::cerr << "File could not be opened!" << std::endl;
		//exit(-1);
	}

	double d;
	while (source.read(reinterpret_cast<char*>(&d), sizeof(d))) //Read
		std::cout << d << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
} //source.close() is executed by the destructor