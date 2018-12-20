#include <iostream>

#include "C.h"
#include <cassert>

int main()
{
	//Class A
	std::cout << "Test 1" << '\n';
	A a1(1);
	const A a2(2);
	a1.output();
	std::cout << '\n';
	a1 = a2;
	std::cout << "a1 after assigning a1 = a2:" << '\n';
	a1.output();
	std::cout << '\n';
	assert(a1 == a2);

	//Class B
	std::cout << '\n' << "Test 2" << '\n';
	B b1(1, 2);
	const B b2(3, 4);
	b1.output();
	std::cout << '\n';
	b1 = b2;
	std::cout << "b1 after assigning b1 = b2:" << '\n';
	b1.output();
	std::cout << '\n';
	assert(b1 == b2);

	std::cout << '\n' << "Test 3: Polymorphic assignment" << '\n';
	const B b3(5, 6);
	A& ar = b1; //Upper class reference
	ar = b3;
	std::cout << "ar after assigning ar = b3:" << '\n';
	ar.output();
	std::cout << '\n';
	assert(ar == b3);

	//Class C
	std::cout << '\n' << "Test 4" << '\n';
	C c1(1, 2, 3);
	C c2(4, 5, 6);
	c1.output();
	std::cout << '\n';
	c1 = c2;
	std::cout << "c1 after assigning c1 = c2:" << '\n';
	c1.output();
	std::cout << '\n';
	assert(c1 == c2);

	std::cout << '\n' << "Test 5: Polymorphic assignment A& = C" << '\n';
	const C c3(7, 8, 9);
	A& arc = c2; //Upper class reference
	arc = c3;
	std::cout << "arg after assigning arc = c3:" << '\n';
	arc.output();
	std::cout << '\n';
	assert(arc == c3);

	std::cout << '\n' << "Test 6: Polymorphic assignment B& = C" << '\n';
	B& brc(c2); //Upper class reference
	brc = c3;
	std::cout << "brc after assigning brc = c3:" << '\n';
	brc.output();
	std::cout << '\n';
	assert(brc == c3);

	std::cout << '\n' << "Test 7: Wrong type: b1 = c3" << '\n';
	try
	{
		b1 = c3;
	}
	catch (const std::bad_typeid& e)
	{
		std::cerr << "Wrong type! Exception: " << e.what() << '\n';
	}

	std::cout << '\n' << "Test 8: Wrong type: a1 = c3" << '\n';
	try
	{
		a1 = c3;
	}
	catch(const std::bad_typeid& e)
	{
		std::cerr << "Wrong type! Exception: " << e.what() << '\n';
	}
	std::cout << "Test-End" << '\n' << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}