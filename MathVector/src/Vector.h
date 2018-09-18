#pragma once

#include <stdexcept>
#include <initializer_list>

template<typename T> 
class Vector
{
public:
	explicit Vector(std::size_t amount = 1);
	Vector(std::size_t amount, T value);
	Vector(std::initializer_list<T>);
	Vector(const Vector<T>& v);
	virtual ~Vector()
	{
		delete[] m_start;
	}

	auto size() const { return m_amount; }

	void changeSize(std::size_t);

	T& operator[](std::size_t index)
	{
		if (index >= m_amount)
			throw std::out_of_range("Index exceeded!");

		return m_start[index];
	}

	const T& operator[](std::size_t index) const
	{
		if (index >= m_amount)
			throw std::out_of_range("Index exceeded!");

		return m_start[index];
	}

	Vector<T>& operator=(Vector<T>);
	void swap(Vector<T>& v) noexcept;

	T* begin() { return m_start; }
	T* end() { return m_start + m_amount; }
	const T* begin() const { return m_start; }
	const T* end() const { return m_start + m_amount; }

private:
	std::size_t m_amount;
	T* m_start;
};

template<typename T>
Vector<T>::Vector(std::size_t amount)
	: m_amount{amount}, m_start{new T[amount]}
{
}

template <typename T>
Vector<T>::Vector(std::size_t amount, T value)
	: Vector(amount)
{
	for (std::size_t i = 0; i < m_amount; ++i)
		m_start[i] = value;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
	: Vector(list.size())
{
	std::copy(list.begin(), list.end(), m_start);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v)
	: Vector(v.m_amount)
{
	for (std::size_t i = 0; i < m_amount; ++i)
		m_start[i] = v.m_start[i];
}

template <typename T>
void Vector<T>::swap(Vector<T>& v) noexcept
{
	std::swap(m_amount, v.m_amount);
	std::swap(m_start, v.m_start);
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> v)
{
	swap(v);

	return *this;
}

template <typename T>
void Vector<T>::changeSize(std::size_t newSize)
{
	T* pTemp{ new T[newSize] };
	const std::size_t smallerNumber{ newSize > m_amount ? m_amount : newSize };
	for (std::size_t i = 0; i < smallerNumber; ++i)
		pTemp[i] = m_start[i];
	delete[] m_start;
	m_start = pTemp;
	m_amount = newSize;
}
