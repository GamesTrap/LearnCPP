#include <iostream>

#include <fstream>

int main()
{
	std::ofstream target("double.dat", std::ios::binary);
	if(!target)
	{
		std::cerr << "File could not be opened!" << std::endl;
		//exit(-1);
	}

	//Write 20 double numbers
	double d = 1.0;
	for (int i = 0; i < 20; ++i, d *= 1.1)
		target.write(reinterpret_cast<const char*>(&d), sizeof(d));
	//target.close() is executed by the destructor

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}