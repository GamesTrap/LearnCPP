#pragma once

#include <condition_variable>
#include <mutex>

#if (defined(_WIN32) || defined(_WIN64))
	#include <thread>
#else
	#include <pthread.h>
#endif

inline std::mutex outputMutex;

class Stack
{
public:
	int Get()
	{
		std::unique_lock<std::mutex> lock(m_monitorMutex);
		while(!m_busy)
		{
			m_cond.wait(lock);
			if (m_terminated)
				throw "Get()-wait Terminated";
		}
		m_busy = false;
		m_cond.notify_one();

		return m_content;
	}

	void Put(const int value)
	{
		std::unique_lock<std::mutex> lock(m_monitorMutex);
		while(m_busy)
		{
			m_cond.wait(lock);
			if (m_terminated)
				throw "Put()-wait Terminated";
		}
		m_busy = true;
		m_content = value;
		m_cond.notify_one();
	}

	void Terminate() //All wait() calls inevitably stop
	{
		m_terminated = true;
		m_cond.notify_all();
	}

private:
	bool m_busy{ false };
	bool m_terminated{ false };
	int m_content = 0;
	std::mutex m_monitorMutex;
	std::condition_variable m_cond;
};