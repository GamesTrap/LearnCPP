#pragma once
#include <mutex>
#include <iostream>

#if (defined(_WIN32) || defined(_WIN64))
	#include <thread>
#else
	#include <pthread>
#endif

class Worker
{
public:
	Worker() = default;

	void operator()()
	{
		while(!m_terminated)
		{
			std::cout << "Worker at work!" << std::endl;
			BreakOrNot();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		std::cout << "Worker is going home!" << std::endl;
	}

	void Wait()
	{
		std::lock_guard<std::mutex> lock(m_mtxPause);
		m_paused = true;
	}

	void Continue()
	{
		std::lock_guard<std::mutex> lock(m_mtxPause);
		m_paused = false;
		m_cond.notify_one();
	}

	void Terminate()
	{
		m_terminated = true;
		m_cond.notify_one(); //... if in pausing state
	}

	bool IsTerminated() const
	{
		return m_terminated;
	}

private:
	bool m_paused{ false };
	bool m_terminated{ false };
	std::mutex m_mtxPause;
	std::condition_variable m_cond;

	void BreakOrNot()
	{
		std::mutex mtx;
		std::unique_lock<std::mutex> lock(mtx);

		while(m_paused && !m_terminated)
		{
			std::cout << "Worker paused!" << std::endl;
			m_cond.wait(lock);
			std::cout << "Worker continues!" << std::endl;
		}
	}
};
