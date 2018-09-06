#pragma once

#include <list>

template <typename T>
class Queue : private std::list<T> //With private inheritance
{
	//(Implementation inheritance)
public:
	using std::list<T>::empty;
	using std::list<T>::size;
	void push(const T& x) { std::list<T>::push_back(x); } //Insert at the end
	void pop() { std::list<T>::pop_front(); } //At the beginning
	using std::list<T>::front; //Read in the beginning
	using std::list<T>::back; //Read in the end
};