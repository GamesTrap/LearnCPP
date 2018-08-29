#include <iostream>

#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n';

class Base
{
public:
	explicit Base(const double b = 0.0)
		: m_bValue(b)
	{}

	virtual ~Base() //Virtual destructor!
	{
		std::cout << "Object " << m_bValue << " Base destructor called!" << '\n';
	}

	Base(const Base&) = default; //Rule of five
	Base(Base&& base) = default; //Rule of five
	Base& operator=(const Base&) = default; //Rule of five
	Base& operator=(Base&& base) = default; //Rule of five

private:
	double m_bValue;
};

class Derived : public Base
{
public:
	explicit Derived(const double b = 0.0, const double d = 0.0)
		: Base(b), m_dValue(d)
	{}

	~Derived()
	{
		std::cout << "Object " << m_dValue << " Derived destructor called!" << '\n';
	}
	Derived(const Derived&) = default; //Rule of five
	Derived(Derived&& derived) = default; //Rule of five
	Derived& operator=(const Derived&) = default; //Rule of five
	Derived& operator=(Derived&& derived) = default; //Rule of five

private:
	double m_dValue;
};

int main()
{
	Base* pb = new Base(1.0);
	PRINT(sizeof(*pb));

	Derived* pd = new Derived(2.0, 2.2);
	PRINT(sizeof(*pd));

	Base* pbd = new Derived(3.0, 3.3);
	PRINT(sizeof(*pbd));

	std::cout << "Delete pb:" << '\n';
	delete pb; //Ok

	std::cout << "Delete pd:" << '\n';
	delete pd; //Ok

	std::cout << "Delete pbd" << '\n';
	delete pbd; //Ok only with virtual destructor! 

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}