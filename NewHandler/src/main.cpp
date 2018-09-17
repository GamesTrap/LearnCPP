#include <iostream>

void memoryError()
{
	std::cerr << "Memory exhausted! Own new_handler called!" << std::endl;
	//Other possible operations omitted
	//Assumption: Procurement of further memory has failed
	//Therefore: pass on exception.
	throw std::bad_alloc();
}

int main()
{
	std::set_new_handler(memoryError);

	std::cout << "Number of gigabytes to reserve: ";
	std::size_t amount;
	std::cin >> amount;

	try
	{
		char* memory = new char[amount * 1'000'000'000L];
		std::cout << amount << " GB easily procured." << '\n';
		delete[] memory;
	}
	catch(const std::bad_alloc& exc)
	{
		std::cerr << amount << " GB could not be procured! " << exc.what() << '\n';
	}

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore();
	std::cin.get();
	return 0;
}