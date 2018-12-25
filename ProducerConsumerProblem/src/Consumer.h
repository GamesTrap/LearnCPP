#pragma once

#include "Stack.h"
#include <iostream>

class Consumer
{
public:
	explicit Consumer(Stack& a)
		: m_stack(a)
	{		
	}

	void operator()() const
	{
		try
		{
			while(true) //Abort with exception
			{
				const int value = m_stack.Get(); //Exception source
				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "Consumer brought " << value << std::endl;
			}
		} catch(...)
		{
			std::lock_guard<std::mutex> lock(outputMutex);
			std::cout << "Consumer ends." << std::endl;
		}
	}

private:
	Stack& m_stack;
};