#include <iostream>
#include "Stack.h"
#include "Consumer.h"
#include "Producer.h"

int main()
{
	Stack stack;
	Producer p1(stack, 1);
	Producer p2(stack, 2);
	Consumer c(stack);
	//Start threads
	std::thread tp1(std::ref(p1));
	std::thread tp2(std::ref(p2));
	std::thread tc(std::ref(c));
	//Waiting for the end of the producer:
	tp1.join();
	tp2.join();
	//Wait until everything is picked up.
	//Here is a long wait, because the consumer can not know how much else could be filed.
	std::this_thread::sleep_for(std::chrono::seconds(2));
	stack.Terminate(); //Terminate waiting Get() calls
	tc.join(); //Waiting for the end of the consumer

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}