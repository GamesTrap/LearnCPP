#pragma once

//Alternative for reference_wrapper
template<class Callee>
class CallWrapper
{
public:
	CallWrapper(Callee& c)
		: m_callee(c)
	{		
	}

	void operator()() const { m_callee(); }

private:
	Callee& m_callee;
};