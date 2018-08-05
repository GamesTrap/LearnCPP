#include <iostream>

//Workin values: V1, V2, V3
#define V1

int main()
{
#ifdef V1
	int number = 0;
	char character;
	std::cout << "Please enter a character: ";
	std::cin >> character;

	if (character == 'I')
		number = 1;
	else if (character == 'V')
		number = 5;
	else if (character == 'X')
		number = 10;
	else if (character == 'L')
		number = 50;
	else if (character == 'C')
		number = 100;
	else if (character == 'D')
		number = 500;
	else if (character == 'M')
		number = 1000;

	if (number == 0)
		std::cout << "No Roman numeral!" << '\n';
	else
		std::cout << number << '\n';
#endif

#ifdef V2
	int number{ -1 };
	char character;
	std::cout << "Please enter a character: ";
	std::cin >> character;

	switch (character)
	{
	case 'I':
		number = 1;
		break;
	case 'V':
		number = 5;
		break;
	case 'X':
		number = 10;
		break;
	case 'L':
		number = 50;
		break;
	case 'C':
		number = 100;
		break;
	case 'D':
		number = 500;
		break;
	case 'M':
		number = 1000;
		break;

	default:
		number = 0;
	}

	if (number > 0)
		std::cout << "Number = " << number;
	else
		std::cout << "No Roman numeral!";
	std::cout << '\n';
#endif

#ifdef V3
	int number{ -1 };
	char character;
	std::cout << "Please enter a character: ";
	std::cin >> character;

	switch (character)
	{
	case 'i':
		[[fallthrough]];
	case 'I':
		number = 1;
		break;
	case'v':
		[[fallthrough]];
	case'V':
		number = 5;
		break;
	case'x':
		[[fallthrough]];
	case'X':
		number = 10;
		break;
	case'l':
		[[fallthrough]];
	case'L':
		number = 50;
		break;
	case'c':
		[[fallthrough]];
	case'C':
		number = 100;
		break;
	case'd':
		[[fallthrough]];
	case'D':
		number = 500;
		break;
	case'm':
		[[fallthrough]];
	case'M':
		number = 1000;
		break;

	default:
		number = 0;
	}

	if (number > 0)
		std::cout << "Number = " << number;
	else
		std::cout << "No roman numeral!";
	std::cout << '\n';

#endif

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}