#pragma once

#include <iostream>
#include <cassert>
#include <string>

template <typename T> class Array2D
{
public:
	Array2D(const std::size_t r, const std::size_t c)
		: m_rows{ r }, m_columns{ c }, m_ptr{ new T[r * c] }
	{}
	Array2D(const std::size_t r, const std::size_t c, const T& value)
		: Array2D(r, c) //Delegate to the above constructor
	{
		init(value);
	}
	Array2D(const Array2D& a) : Array2D(a.m_rows, a.m_columns) //Delegate to the above constructor
	{
		const std::size_t amount = m_rows * m_columns;
		for (std::size_t i = 0; i < amount; ++i)
			m_ptr[i] = a.m_ptr[i];
	}
	Array2D(Array2D&& a) = default;

	~Array2D()
	{
		delete[] m_ptr;
	}

	Array2D& operator=(const Array2D& arr) = delete; //(still) forbid
	Array2D& operator=(Array2D&& arr) = delete; //(still) forbid

	Array2D& assign(Array2D tmp)
	{
		swap(tmp);
		return *this;
	}

	std::size_t getRows() const
	{
		return m_rows;
	}
	std::size_t getColumns() const
	{
		return m_columns;
	}

	void init(const T& value)
	{
		const std::size_t amount = m_rows * m_columns;
		for (std::size_t i = 0; i < amount; ++i)
			m_ptr[i] = value;
	}

	const T& at(const std::size_t r, const std::size_t c) const
	{
		assert(r < m_rows && c < m_columns);
		return m_ptr[r * m_columns + c];
	}
	T& at(const std::size_t r, const std::size_t c)
	{
		assert(r < m_rows && c < m_columns);
		return m_ptr[r * m_columns + c];
	}

	void swap(Array2D& a) noexcept
	{
		std::size_t temp = m_rows;
		m_rows = a.m_rows;
		a.m_rows = temp;
		temp = m_columns;
		m_columns = a.m_columns;
		a.m_columns = temp;
		T* tempPtr = m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = tempPtr;
	}

private:
	std::size_t m_rows{};
	std::size_t m_columns{};
	T* m_ptr;
};

//Global function for output
template <typename T> void printArray(const Array2D<T>& a) 
{
	for (std::size_t z = 0; z < a.getRows(); ++z) 
	{
		for (std::size_t s = 0; s < a.getColumns(); ++s) 
			std::cout << a.at(z, s) << " ";
		std::cout << '\n';
	}
}