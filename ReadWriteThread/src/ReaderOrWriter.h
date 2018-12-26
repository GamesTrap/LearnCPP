#pragma once

#include <utility>
#include "Random.h"
#include "Resource.h"

class ReaderOrWriter
{
public:
	virtual void operator()() = 0;
	virtual void Terminate() final
	{
		m_terminated = true;
	}

protected:
	ReaderOrWriter(Resource& r, std::string i)
		: m_resource(r), m_id{std::move(i)}
	{		
	}
	virtual ~ReaderOrWriter() = default;
	ReaderOrWriter(const ReaderOrWriter&) = default;
	ReaderOrWriter& operator=(const ReaderOrWriter&) = default;

	bool m_terminated{ false };
	Resource& m_resource;
	std::string m_id;
	Random m_random{ 500,1000 };
};