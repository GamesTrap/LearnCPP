#include <iostream>
#include "Vector.h"

#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n'

//Global output operator for vectors
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
	//Improvements in the output layout are possible!
	for(auto i = 0u; i < v.size(); ++i)
	{
		os << v[i] << '\t';
		if ((i + 1) % 8 == 0 || i == v.size() - 1)
			os << '\n';
	}

	return os;
}

int main()
{
	Vector<int> v(3, 7);
	PRINT(v);
	PRINT(v.size());
	v[0] = 1000;
	PRINT(v);

	constexpr auto AMO = 16u;
	std::cout << "Enlarge the vector as needed:" << '\n';
	for(auto i = 0u; i < AMO; ++i)
	{
		if(i ==v.size()) //Space consumed
		{
			v.changeSize(i + 10);
			std::cout << "new: ";
			PRINT(v.size());
		}
		v[i] = i * i;
	}

	std::cout << "Only the first " << AMO << " elements are defined:" << '\n';
	std::cout << "Output operator: cout << v:" << '\n';
	std::cout << v << '\n';

	std::cout << "Reduce vector to " << AMO << " elements:" << '\n';
	v.changeSize(AMO);
	PRINT(v);
	PRINT(v.size());
	std::cout << '\n' << "Provoke program abort with index error:" << '\n';

	try
	{
		v[v.size()] = 8; //v.size () is too much! correct would be 0 .. (v.size() - 1)
	}
	catch(const std::out_of_range& ex)
	{
		std::cerr << "Exception captured: " << ex.what() << '\n';
	}
	std::cout << '\n' << "Create const vector" << '\n';
	const Vector<int> vc(10, 2);
	std::cout << vc << '\n';
	//vc[0] = 1; //Not allowed for const vector
	std::cout << '\n' << "Allocation" << '\n';
	v = vc;
	PRINT(v);
	std::cout << '\n' << "Test of the sequence constructor" << '\n';
	const Vector<int> v1{ 9,8,7,6,5,4,3 };
	PRINT(v1);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}