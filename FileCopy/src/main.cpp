#include <iostream>

#include <string>
#include <fstream>

int main()
{
	std::string filename;
	std::cout << "Please enter an existing filename: ";
	std::cin >> filename;

	std::ifstream source(filename, std::ios::binary); //Object for input file
	if(!source.good()) //Error checking
	{
		std::cerr << filename << " could not be opened!" << '\n';
		exit(-1);
	}

	std::cout << "Please enter a new filename: ";
	std::cin >> filename;
	//Defining and opening the output file
	std::ofstream target(filename, std::ios::binary);
	if(!target.good()) //Error checking
	{
		std::cerr << filename << " could not be opened!" << '\n';
		exit(-1);
	}

	char ch;
	while (source.get(ch))
		target.put(ch); //Copy character by character

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
} //Files are automatically closed at the end of the program.