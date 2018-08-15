#pragma once

#include <initializer_list>
#include <vector>

class NumberSequence
{
public:
	NumberSequence();
	explicit NumberSequence(int i);
	NumberSequence(int i1, int i2);
	NumberSequence(std::initializer_list<int> list);

	void print() const;

private:
	std::vector<int> m_sequence;
};