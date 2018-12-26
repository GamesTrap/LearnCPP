#pragma once

#include "ReaderOrWriter.h"

class Writer : public ReaderOrWriter
{
public:
	Writer(Resource& r, const std::string& i)
		: ReaderOrWriter(r, std::string("Writer ") + i)
	{
	}

	void operator()() override
	{
		int no = 0;
		while(!m_terminated)
		{
			std::string message("Message No.");
			//Convert number to string
			message += std::to_string(++no);
			m_resource.Write(message, m_id);
			//Randomly delay the next write:
			std::this_thread::sleep_for(std::chrono::milliseconds(m_random()));
		}
		Resource::PrintLn(m_id + " ends.");
	}
};