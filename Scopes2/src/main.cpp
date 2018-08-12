#include <iostream>

int a{ 1 }; //Lnown everywhere, so global

void f1() //Declaration and definition
{
	const int c{ 3 }; //Only known in f1(), so local
	std::cout << "f1: c = " << c << '\n';
	std::cout << "f1: Global a = " << a << '\n';
}

int main()
{
	std::cout << "main: Global a = " << a << '\n';

	//std::cout << "f1: c = " << c; //Is not compilable because c is unknown in main().
	f1(); //Call f1()

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}