#pragma once

#include "CountingObject.h"

class Guard
{
public:
	Guard() = default;
	~Guard()
	{
		if (!CountingObject::m_objects.empty())
			std::cerr << "There are " << CountingObject::m_objects.size() << " delete statements missing!" << '\n';
	}
	Guard(const Guard&) = delete; //Copy not desired
	Guard(Guard&&) = delete; //Move not desired
	Guard& operator=(const Guard&) = delete; //Assignment not desired
	Guard& operator=(Guard&&) = delete; //Move assignment not desired
};