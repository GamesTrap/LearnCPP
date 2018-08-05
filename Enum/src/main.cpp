#include <iostream>

enum class Colortype :int { red, yellow, green };
enum class RGB { red = 'R', green = 'G', blue = 'B' };

int main()
{
	Colortype color = Colortype::yellow;
	std::cout << "Colortype::yellow = " << static_cast<int>(color) << '\n'; //1
	std::cout << "RGB::green = " << static_cast<char>(RGB::green) << '\n'; //G
	//Different initialization options
	RGB rgb1{ RGB::blue }; //Correct!
	std::cout << "rgb1 = " << static_cast<char>(rgb1) << '\n'; //B
	RGB rgb2{ 'G' }; //Not recommended!
	//Reason: RGB rgb2 {'X'}; is also possible WITHOUT warning by the compiler
	std::cout << "rgb1 = " << static_cast<char>(rgb2) << '\n'; //G

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}