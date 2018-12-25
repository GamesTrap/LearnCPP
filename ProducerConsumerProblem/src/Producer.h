#pragma once

#include "Stack.h"
#include "Random.h"
#include <chrono>
#include <iostream>

class Producer
{
public:
	Producer(Stack& a, const int i)
		: m_stack(a), m_id{i}
	{		
	}

	void operator()()
	{
		for(int i = 0; i < 5; ++i)
		{
			const int value{ m_id * 10 + i };
			std::this_thread::sleep_for(std::chrono::milliseconds(200 + m_random()));
			try
			{
				m_stack.Put(value);
				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "Producer #" << m_id << " is storing: " << value << std::endl;
			} catch(...)
			{
				break; //Producer is terminated
			}
		}
		std::lock_guard<std::mutex> lock(outputMutex);
		std::cout << "Producer " << m_id << " ends." << std::endl;
	}

private:
	Stack& m_stack;
	int m_id;
	Random m_random{ 500 };
};