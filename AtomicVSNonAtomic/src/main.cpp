#include <iostream>
#include <atomic>
#include "ThreadGroup.h"

int nonAtomicCounter{ 0 };
std::atomic<int> atomicCounter{ 0 };

void TestAtomicActivity()
{
	for(int i = 0; i < 1000; ++i)
	{
		++nonAtomicCounter;
		++atomicCounter;
	}
}

int main()
{
	ThreadGroup threadGroup;
	for (int i = 0; i < 100; ++i)
		threadGroup.AddThread(TestAtomicActivity);
	threadGroup.JoinAll();
	std::cout << "Non atomic counter = " << nonAtomicCounter << '\n';
	std::cout << "Atomic counter = " << atomicCounter << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}