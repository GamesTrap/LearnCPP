#include <iostream>

//a and b are declared outside each block.
//They are therefore valid within any other block and are therefore called global variables.
int a{ 1 };
int b{ 2 };

int main() //A new block begins.
{
	std::cout << "Global a = " << a << '\n'; //Output of a

	//Within the block, a variable a is declared.
	//From now on, the global a is still valid, but not visible under the name a, as the following line shows.
	const int a{ 10 };
	//THe value of local a is output:
	std::cout << "Local a = " << a << '\n';

	//The global a can only be addressed after the declaration of the local a using the scope operator ::.
	//Output of a.

	std::cout << "Global ::a = " << ::a << '\n';
	{ //A new block begins within the existing one.
		const int b{ 20 };
		//Variable b is declared within this block.
		//This does not invalidate the global b, but invisible.
		const int c{ 30 }; //c is declared within this block.
		//The values of b and c are output.
		std::cout << "Local b = " << b << '\n';
		std::cout << "Local c = " << c << '\n';

		//As described above, the global b can only be addressed via the scope operator.
		//Output of ::b.
		std::cout << "Global ::b = " << ::b << '\n';
	} //The inner block is closed.
	//This makes the global b visible again without a scope operator:
	std::cout << "Global b visible again: b = " << b << '\n';

	//std::cout << "c = " << c << '\n'; //Error

	std::cout << "Press any key to continue . . . ";
	std::cin.get();
	return 0;
}//End of the outer block