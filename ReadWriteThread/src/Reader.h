#pragma once

#include "ReaderOrWriter.h"

class Reader : public ReaderOrWriter
{
public:
	Reader(Resource& r, const std::string& i)
		: ReaderOrWriter(r, std::string("Reader ") + i)
	{		
	}

	void operator()() override
	{
		while(!m_terminated)
		{
			std::string content = m_resource.Read(m_id);
			//Randomly delay the next read:
			std::this_thread::sleep_for(std::chrono::milliseconds(m_random()));
		}
		Resource::PrintLn(m_id + " ends.");
	}
};