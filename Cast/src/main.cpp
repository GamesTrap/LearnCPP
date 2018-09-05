#include <iostream>

class Base
{
public:
	virtual void f() {}
	virtual ~Base() = default;
	Base() = default;
	Base(const Base&) = default;
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
};

class Derived : public Base
{
public:
	virtual void f() {}
};

Derived* g(Base *pB) //g() uses f()
{
	Derived *pD = dynamic_cast<Derived*>(pB);
	if (pD) //Null pointer on failure of the dynamic_cast
		pD->f(); //Derived::f()

	return static_cast<Derived*>(pB);
}

int main()
{
	Base b;
	Derived d;
	Base *pBB = &b;
	Base *pBD = &d;
	//The following call to g() executes in g() Derived::f() because pBD points to a Derived object. pResult shows on d:
	Derived* pResult = g(pBD);
	//Derived::f() is NOT executed below, because pB in g() points to a base object. pResult is undefined(!) because the static_cast is inappropriate:
	//The dynamic type of the pointer-passed object is not of type Derived.
	pResult = g(pBB);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}