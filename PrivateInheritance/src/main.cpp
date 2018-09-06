#include <iostream>

#include <string_view>
#include "Queue.h" //Select one
//#include "QueueD.h"

int main()
{
	Queue<std::string_view> fifo;
	fifo.push("one");
	fifo.push("two");
	fifo.push("three");

	while(!fifo.empty())
	{
		std::cout << fifo.size() << " Element(s) available!" << '\n';
		const auto buf = fifo.front(); //Read
		std::cout << "Element " << buf << " removed" << '\n';
		fifo.pop(); //Remove
	}
	std::cout << "List is empty!" << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}