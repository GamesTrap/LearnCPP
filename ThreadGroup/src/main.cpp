#include <iostream>
#include <mutex>
#include "ThreadGroup.h"

namespace
{
	std::mutex mtx;
}

class Even
{
public:
	Even()
		: m_n(0)
	{}

	int Next()
	{
		//std::lock_guard<std::mutex> lock(mtx); //Uncomment for correct results

		++m_n;
		++m_n;

		return m_n;
	}

	int GetValue() const
	{
		return m_n;
	}

private:
	int m_n;
};

Even e;

void TestEven()
{
	for(int i = 0; i < 10000; ++i)
	{
		const int value = e.Next();
		if(value % 2 != 0)
		{
			std::cout << value << " is odd! Thread terminated." << '\n';
			break;
		}
	}
}

int main()
{
	ThreadGroup threadGroup;
	for (int i = 0; i < 20; ++i)
		threadGroup.AddThread(TestEven);
	threadGroup.JoinAll();

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}