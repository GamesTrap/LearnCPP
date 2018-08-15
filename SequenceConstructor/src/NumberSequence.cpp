#include "NumberSequence.h"

#include <iostream>

NumberSequence::NumberSequence() { std::cout << "NumberSequence() "; }
NumberSequence::NumberSequence(int i)
{
	std::cout << "NumberSequence(int) ";
	m_sequence.push_back(i);
}
NumberSequence::NumberSequence(int i1, int i2)
{
	std::cout << "NumberSequence(int, int) ";
	m_sequence.push_back(i1);
	m_sequence.push_back(i2);
}
NumberSequence::NumberSequence(std::initializer_list<int> list)
{
	std::cout << "NumberSequence(initializer_list) ";
	m_sequence.assign(list);
}

void NumberSequence::print() const
{
	std::cout << "Sequence: ";
	for (auto element : m_sequence)
		std::cout << element << ' ';
	std::cout << '\n';
}