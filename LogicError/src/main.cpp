#include <iostream>
#include "Assertex.h"

//#define NDEBUG 1 //If necessary, deactivate the assurances with NDEBUG

class EqualsNull //Exception class without constructor parameter
{
public:
	static auto what()
	{
		return "Error EqualsNull found";
	}
};

class UnequalOne //Exception class with constructor parameter
{
public:
	explicit UnequalOne(const int i)
		: m_number{i}
	{		
	}

	static auto what()
	{
		return "Error UnequalOne found";
	}

	auto howMuch()const
	{
		return m_number;
	}

private:
	int m_number;
};

int main()
{
	int i;
	std::cout << "0 : EqualNull error" << '\n'
		      << "1 : Normal ending" << '\n'
		      << "!= 1 : UnequalOne error" << '\n'
		      << "i = ?: ";
	std::cin >> i;

	try
	{
		ASSERT(i, EqualsNull());
		ASSERT(i == 1, UnequalOne(i));
	}
	catch(const EqualsNull& errorObject)
	{
		std::cerr << errorObject.what() << '\n' << " no further error handling" << '\n';
	}
	catch(const UnequalOne& errorObject)
	{
		std::cerr << errorObject.what() << '\n'
			      << errorObject.howMuch() << "! Abort" << '\n';

		std::cout << "Press Enter to continue . . . ";
		std::cin.ignore();
		std::cin.get();
		exit(1); //Program termination
	}
	std::cout << "Normal program termination with i = " << i << '\n';
#ifdef NDEBUG
	std::cout << "NDEBUG is set: Assert is switched off." << '\n';
#endif

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(); 
	std::cin.get();
	return 0;
}