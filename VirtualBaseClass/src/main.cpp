#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base standard constructor" << '\n'; }
	explicit Base(const char* a) { std::cout << a << '\n'; }
	virtual ~Base() = default; //Virtual destructor
	Base(const Base&) = default;
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
};

class Left : virtual public Base
{
public:
	explicit Left(const char* a)
		//: Base(a)
	{}
};

class Right : virtual public Base
{
public:
	explicit Right(const char* a)
	    : Base(a)
	{}
};

class Down : public Left, public Right
{
public:
	explicit Down(const char* a)
		: //Base(a),
 	      Left(a),
	      Right(a)
	{}
};

int main()
{
	Down x("Down");
	Left le("Left");

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}