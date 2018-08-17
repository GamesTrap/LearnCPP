#include <iostream>

template<typename T>
bool smaller(const T& a, const T& b) //Comparison
{
	std::cout << "Template" << '\n';
	return (a < b);
}

template<>
bool smaller(const int& a, const int& b) //Specialised
{
	std::cout << "Specialised Template" << '\n';
	return(a < b);
}

bool smallerFunc(const int a, const int b) //Normal function
{
	std::cout << "Normal Function" << '\n';
	return(a < b);
}

int main()
{
	//Template, Output 1.9:
	std::cout << (smaller(1.9, 9.7) ? 1.9 : 9.7) << '\n';

	//Specialised template or function, Output 3
	std::cout << (smaller(3, 6) ? 3 : 6) << '\n';

	//The following line is not compiled.
	//For templates, the type check is sharper.
	//std::cout << (smaller(3.1, 3) ? 3.1 : 3.0) << '\n';

	//Is compiled, but gives a wrong result because
	//of the loss of accuracy int the conversion!
	std::cout << (smallerFunc(3.1, 3.3) ? 3.1 : 3.3) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}