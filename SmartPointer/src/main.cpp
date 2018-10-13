#include <iostream>
#include "SmartPointer.h"

class A
{
public:
	virtual void hi()
	{
		std::cout << "Here is A::hi()" << '\n';
	}

	virtual ~A()
	{
		std::cout << "A::Destructor" << '\n';
	}
	A() = default;
	A(const A&) = default;
	A(A&&) = default;
	A& operator=(const A&) = default;
	A& operator=(A&&) = default;
};

class B : public A
{
public:
	virtual void hi()
	{
		std::cout << "Here is B::hi()" << '\n';
	}
	virtual ~B()
	{
		std::cout << "B::Destructor" << '\n';
	}
	B() = default;
	B(const B&) = default;
	B(B&&) = default;
	B& operator=(const B&) = default;
	B& operator=(B&&) = default;
};

//Transfer by value is not possible here, but by reference:
template <class T> void byReference(const SmartPointer<T>& p)
{
	std::cout << "Call: byReference(const SmartPointer<T>&):";
	p->hi(); //(p.operator->())->hi();
}

int main()
{
	std::cout << "Pointer to dynamic objects:" << '\n';
	std::cout << "Constructor calls" << '\n';
	SmartPointer<A> spA(new A);

	std::cout << "Operator ->" << '\n';
	spA->hi();

	std::cout << "Operator *" << '\n';
	(*spA).hi();

	std::cout << "Polymorphism:" << '\n';
	SmartPointer<A> spAB(new B); //Points to B object
	spAB->hi(); //B::hi()

	//Parameter transfer of a SmartPointer
	byReference(spAB);

	//The effect of the safety measures compared to simple C-pointers are shown in the following lines:
	SmartPointer<B> spUndef;
	try
	{
		if (!spUndef) //= if(!(spUndef.operator bool()))
			std::cout << "undefined pointer:" << '\n';
		//Access to uninitialized pointer causes runtime error:
		spUndef->hi(); //Runtime error!
		(*spUndef).hi(); //Runtime error!
	}
	catch( const NullPointerException& ex)
	{
		std::cerr << "Runtime error: " << ex.what() << '\n' << std::endl;
	}

	//All subsequent statements cause error messages from the compiler

	//Type check: a B is not an A!
	//SmartPointer<B> spTyp(new A); //Error!

	//Initialization with copy constructor is not possible:
	//SmartPointer<A> spY = spA; //Error!

	//Assignment is not possible:
	//SmartPointer<A> spA1;
	//spA1 = spA; //Error!

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}