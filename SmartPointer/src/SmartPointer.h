#pragma once

#include "NullPointerException.h"

template <typename T>
class SmartPointer
{
public:
	explicit SmartPointer(T* p = nullptr);
	~SmartPointer(); //Not virtual: Inheritance isn't planned
	T* operator->() const;
	T& operator*() const;
	explicit operator bool() const;

private:
	T* m_pointerToObject;
	void check() const; //Checks for non NULL
	void operator=(const SmartPointer&) = delete; //Prohibit assignment
	SmartPointer(const SmartPointer&) = delete;
	SmartPointer(SmartPointer&&) = delete;
	SmartPointer& operator=(SmartPointer&&) = delete;
};

template <typename T>
SmartPointer<T>::SmartPointer(T* p)
	: m_pointerToObject{ p }
{
}

template <typename T>
void SmartPointer<T>::check() const
{
	if (!m_pointerToObject)
		throw NullPointerException();
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
	delete m_pointerToObject;
}

template <typename T>
T* SmartPointer<T>::operator->() const
{
	check();
	return m_pointerToObject;
}

template <typename T>
T& SmartPointer<T>::operator*() const
{
	check();
	return *m_pointerToObject;
}

template <typename T>
SmartPointer<T>::operator bool() const
{
	return static_cast<bool>(m_pointerToObject);
}