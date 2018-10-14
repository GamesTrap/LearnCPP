#pragma once

#include <stdexcept>

template<typename T, int N>
class MemoryManagement
{
public:
	MemoryManagement()
	{
		for (std::size_t i = 0; i < N; ++i) //Initialize FreeMemoryList
			m_freeMemoryList[i] = &m_memory[sizeof(T) * i];
	}

	static void* getMemory(std::size_t size)
	{
		if (size != sizeof(T))
			throw std::invalid_argument("getMemory(): Type with wrong size!");
		if (m_numOfFreeMemory == 0)
			throw std::bad_alloc();

		return m_freeMemoryList[--m_numOfFreeMemory];
	}

	static void freeMemory(void* ptr)
	{
		if(ptr) //Ignore Null pointer
		{
			//It is assumed, as usual in C ++, that exactly * one * delete per new is called!
			//These errors will not be intercepted.
			//Now enter the vacant position in the heap list:
			m_freeMemoryList[m_numOfFreeMemory++] = ptr;
		}
	}

	static std::size_t freeSpace()
	{
		return m_numOfFreeMemory;
	}

private:
	static std::size_t m_numOfFreeMemory;
	static void* m_freeMemoryList[N];
	static char m_memory[sizeof(T) * N];
};

//Definitions
template<typename T, int N>
std::size_t MemoryManagement<T, N>::m_numOfFreeMemory = N;

template<typename T, int N>
void* MemoryManagement<T, N>::m_freeMemoryList[N];

template<typename T, int N>
char MemoryManagement<T, N>::m_memory[sizeof(T) * N];