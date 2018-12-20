#include <iostream>
#include <fstream>

//Read and Write of ONE file

int main()
{
	//Create file
	std::fstream filestream("fstream.dat", std::ios::out | std::ios::trunc);
	filestream.close(); //Empty file exists now

	//Open file for read and write
	filestream.open("fstream.dat", std::ios::in | std::ios::out);
	//Write
	for (int i = 0; i < 20; ++i)
		filestream << i << ' '; //No EOF directly after the last number
	filestream << '\n';

	//Read
	filestream.seekg(0); //Search start
	while(filestream.good())
	{
		int i; //Helper variable
		filestream >> i; //Read
		if (filestream.good())
			std::cout << i << ' '; //Control output
		else
			std::cout << '\n' << "End of file reached(or read error)";
	}
	std::cout << '\n';
	filestream.clear(); //Delete EOF-Status
	filestream.seekp(5); //Search position 5

	filestream << "new text "; //From pos. 5 overwrite
	filestream.seekg(0); //Search start
	char buf[100];
	filestream.getline(buf, 100); //Read line
	std::cout << buf << '\n' << '\n'; //Control output

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}