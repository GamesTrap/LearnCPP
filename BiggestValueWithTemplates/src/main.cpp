#include <iostream>

#include <string>
#include <vector>

//The following function would also work with a parameter list (T a, T b), i. a copy by value.
//However since T stands for any data type, a reference is preferred to avoid copying potentially large objects.
template<typename T>
bool smaller(const T& a, const T& b) //Comparison
{
	return a < b;
}

template<typename T>
void print(const std::vector<T>& V)
{
	for (const T& value : V)
		std::cout << value << ' ';
	std::cout << '\n';
}

template<typename T>
T biggestValue(const std::vector<T>& vec)
{
	T max = vec[0]; //vec can not be empty
	for (const auto& element : vec)
		if (smaller(max, element))
			max = element;

	return max;
}

int main()
{
	std::vector<int> iV{ -100,22,-3,44,6,-9,-2,1,8,9 };
	//In the following two statements, the compiler controller by the data type
	//vector<int> of the parameter iV, generates from the above templates the
	//functions biggestValue(const std::vector<int>&) and print(const std::vector<int>&),
	//as well the implicitly called function is smaller(const int&, const int&).
	std::cout << "THe biggest value of ";
	print(iV);
	std::cout << " is " << biggestValue(iV) << '\n';
	std::vector<double> dV{ 1.09,2.2,79.6,-1.9,2.7,100.9,18.8,99.9 };
	//Generate the overloaded functions biggestValue
	//(const std::vector<double>&) and print(const std::vector<double>&)
	//(and the called function smaller(const double&, const double&)):
	std::cout << "The biggest value of ";
	print(dV);
	std::cout << " is " << biggestValue(dV) << '\n';
	//This also works for strings:
	std::vector<std::string> sV{ "alpha", "beta", "zebra", "one", "eleven" };
	std::cout << "The biggest value of ";
	print(sV);
	std::cout << " is " << biggestValue(sV) << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}