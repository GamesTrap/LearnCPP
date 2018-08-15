#include <iostream>

class Example
{
public:
	explicit Example(const int i = 0) //Constructor
		: m_number{i}
	{
		std::cout << "Object " << m_number << " is generated." << '\n';
	}

	~Example() //Destructor
	{
		std::cout << "Object " << m_number << " is destroyed." << '\n';
	}

	//Rule of 5
	Example(const Example& example) = default;
	Example(Example&& example) = default;
	Example& operator=(const Example& example) = default;
	Example& operator=(Example&& example) = default;


private:
	int m_number;
};

//Global variable, initialized with 0 by default
Example g_example;

int main()
{
	std::cout << "main is started" << '\n';
	Example example(1);
	{
		std::cout << '\t' << "new block" << '\n';
		Example example(2);
		std::cout << '\t' << "block is left" << '\n';
	}
	std::cout << "main is left" << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}