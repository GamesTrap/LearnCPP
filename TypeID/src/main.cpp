#include <iostream>

#define PRINT(X) std::cout << (#X) << " = " << std::boolalpha << (X) << '\n';

class Base
{
public:
	virtual ~Base() = default; //To provide polymorphic class
	Base() = default;
	Base(const Base&) = default;
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
};

class Derived : public Base {};

int main()
{
	Derived object1;
	Derived object2;
	Base* p = &object1;
	std::cout << typeid(object1).name() << '\n';
	//name(): (compiler-dependent) classname
	PRINT(typeid(object2) == typeid(*p)); //*p is polymorphic

	Base baseObject;
	std::cout << typeid(baseObject).name() << '\n';
	PRINT(typeid(object1) == typeid(baseObject));

	Base* pNull = nullptr;
	PRINT(typeid(object1) == typeid(*pNull)); //Exception

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}