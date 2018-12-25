#pragma once
#include <vector>
#include <functional>

#if (defined(_WIN32 ) || defined(WIN64))
	#include <thread>
#else
	#include <pthread>
#endif

class ThreadGroup
{
public:
	ThreadGroup() = default;
	ThreadGroup(const ThreadGroup&) = delete;
	ThreadGroup& operator=(const ThreadGroup&) = delete;

	template<typename F>
	void AddThread(F& f)
	{
		m_threads.emplace_back(std::ref(f)); //Save and start thread
	}

	void JoinAll() //Wait for all threads to finish
	{
		for (auto& t : m_threads)
			t.join();
	}

	std::size_t Size() const
	{
		return m_threads.size();
	}

private:
	std::vector<std::thread> m_threads;
};
