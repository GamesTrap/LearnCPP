#pragma once

#include <limits>
#include <random>

class Random
{
public:
	explicit Random(const int min, const int max)
		: m_distribution(min, max)
	{		
	}
	explicit  Random(const int max = std::numeric_limits<int>::max())
		: m_distribution(0, max)
	{		
	}

	void SetSeed(const std::size_t newSeed)
	{
		m_generator.seed(newSeed);
	}

	int operator()()
	{
		return m_distribution(m_generator);
	}

private:
	std::mt19937 m_generator;
	std::uniform_int_distribution<> m_distribution;
};