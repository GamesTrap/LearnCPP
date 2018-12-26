#include <iostream>
#include "Reader.h"
#include "Resource.h"
#include "Writer.h"
#include "ThreadGroup.h"

int main()
{
	Resource resource;

	Writer w1(resource, "w1");
	Writer w2(resource, "w2");
	Reader r1(resource, "r1");
	Reader r2(resource, "r2");
	Reader r3(resource, "r3");
	Reader r4(resource, "r4");

	ThreadGroup threadGroup;
	threadGroup.AddThread(w1);
	threadGroup.AddThread(r1);
	threadGroup.AddThread(r2);
	threadGroup.AddThread(r3);
	threadGroup.AddThread(r4);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	threadGroup.AddThread(w2);

	//Run threads for a while
	std::this_thread::sleep_for(std::chrono::seconds(10));
	w1.Terminate();
	w2.Terminate();
	r1.Terminate();
	r2.Terminate();
	r3.Terminate();
	r4.Terminate();
	threadGroup.JoinAll(); //Wait till all is terminated

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}