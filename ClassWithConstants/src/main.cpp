#include <iostream>

#include "Constants.h"
#include <string>

void f(const double x) { std::cout << "f(" << x << ") called!" << '\n'; }
void g(const double& x) { std::cout << "g(" << x << ") called!" << '\n'; }
const std::string PROBLEM = ">" + Constants::CONST_STR1 + "<";

int main()
{
	std::cout << PROBLEM << '\n'; //Output above constant
	//Output of the class constants
	std::cout << Constants::three << '\n';
	std::cout << static_cast<int>(Constants::RGB::BLUE) << '\n';
	std::cout << Constants::CONST_DOUBLE << '\n';
	std::cout << Constants::CONST_INT << '\n';
	std::cout << Constants::CONST_STR1 << '\n';
	std::cout << Constants::CONST_STR2 << '\n';

	//Transfer to functions
	f(Constants::three); //Ok, implicit conversion
	g(Constants::three); //Ok, implicit conversion
	g(static_cast<double>(Constants::RGB::BLUE)); //Ok

	f(Constants::CONST_DOUBLE); //Ok
	g(Constants::CONST_DOUBLE); //Ok only with external definition

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}