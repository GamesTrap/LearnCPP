#include <iostream>
#include <cfenv>

float f(const float a, const float b)
{
	const float c = a / b;

	if(fetestexcept(FE_DIVBYZERO)) //Check
	{
		feclearexcept(FE_DIVBYZERO); //Reset
		throw ("Error: Division by 0!");
	}

	return c;
}

int main()
{
	float n;
	float d;
	std::cout << "Nominator: ";
	std::cin >> n;
	std::cout << "Denominator: ";
	std::cin >> d;

	try
	{
		std::cout << "Result = " << f(n, d) << '\n';
	}
	catch(const char* ex)
	{
		std::cerr << ex << std::endl;
	}
	std::cout << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore();
	std::cin.get();
	return 0;
}