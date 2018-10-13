#include <iostream>

#include "Sine.h"

template <typename Functor>
void ShowFunctorResult(double arg, const Functor& functor)
{
	std::cout << functor(arg) << '\n';
}

int main()
{
	const Sine sinRad;
	const Sine sinAngle(Sine::Mode::angle);

	//Call the objects like a function
	std::cout << "sin(pi/4[rad]) = " << sinRad(PI / 4.0) << ". sin(45[angle]) = " << sinAngle(45.0) << '\n';

	//Transfer of a functor to a function
	ShowFunctorResult(45.0, sinAngle);

	//Lambda equivalent for sinAngle:
	ShowFunctorResult(45.0, [](auto arg) {return std::sin(arg / 180.0 * PI); });

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}