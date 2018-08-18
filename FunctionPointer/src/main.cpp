#include <iostream>

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

int main()
{
	const int a{ 1700 };
	const int b{ 1000 };

	//fp is a pointer to a function
	int(*fp)(int, int);

	do
	{
		char c;
		std::cout << "Output max (1) or min (0) (otherwise = end): ";
		std::cin >> c;

		//Assign max() or min() (without specifying brackets after the function name)
		switch(c)
		{
		case '0':
			fp = &min;
			break;
		case '1':
			fp = max;
			break;

		default:
			fp = nullptr;
		}

		if(fp)
		{
			//Dereferencing of function pointer and call
			std::cout << (*fp)(a, b) << '\n';
			//or direct use of the name (implicit type conversion)
			std::cout << fp(a, b) << '\n';
		}
	} while (fp);

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore();
	std::cin.get();
	return 0;
}