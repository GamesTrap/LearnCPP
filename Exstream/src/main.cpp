#include <iostream>

class FileEnd : public std::exception //Helper class (see below) inherits from exception
{	
};

int readNumber(std::istream& input)
{
	int i;
	input >> i;
	//The eof bit causes the eject of a FileEnd-type object, which is
	//generated here by calling the system-generated constructor, to the surrounding context.
	//THe input of false characters sets the fail bit, which is queried by the function fail()
	//and causes the ejection of a const char* object.
	//Each throw leads to leaving the function.
	if (input.eof())
		throw FileEnd();
	if (input.fail())
		throw "Syntax error";
	if (input.bad())
		throw; //Unrecoverable error

	return i;
}

void readAndOutputNumbers()
{
	int number = 0;
	while(true)
	{
		std::cout << "Enter number: ";

		bool successful = true;
		//Trial block
		try
		{
			//Read number from standard input:
			number = readNumber(std::cin);			
		}

		//Error handling: The following exception handler is jumped
		//when an object of type FileEnd has been ejected in the try block.
		catch(const FileEnd& e)
		{
			std::cout << "End of file reached!" << '\n' << "e.what() returns: " << e.what() << '\n';
			std::cin.clear(); //Reset error bits
			break; //Leave loop
		}
		//The following exception handler is called if an object of type
		//const char* was ejected.
		//The readNumber() function throws a C-string if the input violates the syntax of int-numbers,
		//for example, letters instead of numbers
		catch(const char* c)
		{
			std::cerr << c << std::endl;
			successful = false;
			std::cin.clear(); //Reset error bits
			std::cin.get(); //Remove incorrect character
		}

		//bad() will not be intercepted, possibly abort.
		//Continuation of the program after error handling
		if (successful)
			std::cout << "Number = " << number << '\n';
	}
}

int main()
{
	readAndOutputNumbers();

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}