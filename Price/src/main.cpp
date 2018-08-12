#include <iostream>

#include <string>

//Function prototype, 2nd parameter with default value:
void showPrice(const double price, const std::string& currency = "Euro");

//Main program
int main()
{
	//Two calls with different parameter numbers:
	showPrice(12.35); //Predetermined parameter is used
	showPrice(99.99, "US-Dollar");

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}

//Function implementation
void showPrice(const double price, const std::string& currency)
{
	std::cout << price << ' ' << currency << '\n';
}
