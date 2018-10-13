#pragma once

#include <stdexcept>

class NullPointerException : public std::runtime_error
{
public:
	NullPointerException()
		: std::runtime_error("NullPointerException!")
	{}
};