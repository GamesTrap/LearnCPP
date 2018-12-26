#pragma once

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>

inline std::mutex outputMutex;

class Resource
{
public:
	std::string Read(const std::string& id)
	{
		std::shared_lock<std::shared_mutex> lock(m_rwMutex); //Lock for shared access
		++m_nReader;
		PrintLn(id + "  reads " + m_content + RWProtocol());
		--m_nReader;

		return m_content;
	}

	void Write(const std::string& new_, const std::string& id)
	{
		std::lock_guard<std::shared_mutex> lock(m_rwMutex); //Lock for exclusive access
		++m_nWriter;
		PrintLn(id + "  writes " + new_ + RWProtocol());
		--m_nWriter;
		m_content = new_;
	}

	static void PrintLn(const std::string& what)
	{
		std::lock_guard<std::mutex> lock(outputMutex);
		std::cout << what << std::endl;
	}

private:
	std::string RWProtocol() const
	{
		std::string msg(" Number of active: R=");
		msg += std::to_string(m_nReader) + " W=" + std::to_string(m_nWriter);

		return msg;
	}

	std::string m_content{ "nothing" };
	std::shared_mutex m_rwMutex;

	int m_nReader = 0;
	int m_nWriter = 0;
};