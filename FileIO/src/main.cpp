#include <iostream>

#include <string>
#include <fstream>

int main()
{
	std::string filename;
	std::cout << "Please enter a filename: ";
	std::cin >> filename; //May not contain spaces because of cin!

	//Write file
	std::ofstream file(filename); //Object for output stream

	if (!file.good())
		std::cerr << filename << " can not be written!" << '\n';
	else
	{
		file << "Written text." << '\n' << "Second line!" << '\n';
		file.close(); //Close the file so that it can be read
	}

	//Read the same file and display the lines
	std::ifstream source(filename); //Object for input stream

	std::cout << "The content of " << filename << " is:" << '\n';
	while(source.good())
	{
		std::string line;
		std::getline(source, line); //Read line
		std::cout << line << '\n';
	}

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
} //File is closed automatically at the end of the program.