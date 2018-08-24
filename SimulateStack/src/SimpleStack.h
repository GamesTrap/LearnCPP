//A simple stack template
#pragma once

#include <cassert>
#include <array>

//Parameter MAX_SIZE for defining the stack size
template <typename T, unsigned int MAX_SIZE>
class SimpleStack
{
public:
	bool empty() const { return m_amount == 0; }
	bool full() const { return m_amount == MAX_SIZE; }
	unsigned int size() const { return m_amount; }
	void clear() { m_amount = 0; } //Clear stack

	const T& top() const; //See last element
	void pop(); //Remove element
	//Prerequisite for top and pop: Stack is not empty

	void push(const T& x); //Put x on the stack
	//Prerequisite for push: Stack is not full

private:
	unsigned int m_amount{ 0 }; //Initial value
	std::array<T, MAX_SIZE> m_array{};
};

//Missing implementations
template <typename T, unsigned MAX_SIZE> //Parameter m is not used
const T& SimpleStack<T, MAX_SIZE>::top() const
{
	assert(!empty());
	return m_array.at(m_amount - 1);
}

template <typename T, unsigned MAX_SIZE> //Parameter m is not used
void SimpleStack<T, MAX_SIZE>::pop()
{
	assert(!empty());
	--m_amount;
}

template <typename T, unsigned MAX_SIZE> //Parameter m is not used
void SimpleStack<T, MAX_SIZE>::push(const T& x)
{
	assert(!full());
	m_array.at(m_amount++) = x;
}