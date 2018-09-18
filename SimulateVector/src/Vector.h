//Dynamic Vector class
#pragma once

#include <stdexcept>

template<typename T>
class Vector
{
public:
	explicit Vector(std::size_t amount = 1); //General constructor
	Vector(std::size_t amount, T value); //Second General Constructor: n elements with Value t
	Vector(std::initializer_list<T>); //Sequence constructor
	Vector(const Vector<T>& v); //Copy constructor
	virtual ~Vector() //Destructor
	{
		delete[] m_start;
	}

	auto size() const { return m_amount; }

	void changeSize(std::size_t); //Dynamically change

	T& operator[](std::size_t index) //IndexOperator inline
	{
		if (index >= m_amount)
			throw std::out_of_range("Index exceeded!");

		return m_start[index];
	}

	//IndexOperator for non changeable vectors
	const T& operator[](std::size_t index) const
	{
		if (index >= m_amount)
			throw std::out_of_range("Index exceeded!");

		return m_start[index];
	}

	//Assignment operator
	//Vector<T>& operator=(const Vector<T>&);
	Vector<T>& operator=(Vector<T>); //By value, see implementation below
	void swap(Vector<T>& v) noexcept noexcept; //Swap vectors

	//Pointer to start and end position for vectors with non constant and constant elements
	T* begin() { return m_start; }
	T* end() { return m_start + m_amount; }
	const T* begin() const { return m_start; }
	const T* end() const { return m_start + m_amount; }

private:
	std::size_t m_amount{}; //Amount of data objects
	T* m_start; //Pointer to data objects
};

//********** Implementation **********
template<typename T>
Vector<T>::Vector(std::size_t amount) //General constructor
	: m_amount{amount}, m_start{new T[amount]}
{	
}

template<typename T>
Vector<T>::Vector(std::size_t amount, T value) //General constructor 2
	: Vector(amount) //Delegation to the above constructor
{
	for (std::size_t i = 0; i < m_amount; ++i)
		m_start[i] = value;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) //Sequence constructor
	: Vector(list.size()) //Delegation to the above constructor
{
	std::copy(list.begin(), list.end(), m_start);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) //Copy constructor
	: Vector(v.m_amount) //Delegation to the above constructor
{
	for (std::size_t i = 0; i < m_amount; ++i)
		m_start[i] = v.m_start[i];
}

template<typename T>
void Vector<T>::swap(Vector<T>& v) noexcept noexcept
{
	std::swap(m_amount, v.m_amount);
	std::swap(m_start, v.m_start);
}

//Alternative with 'swap trick'
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> v) //Assignment
{
	swap(v);

	return *this;
}

template <typename T>
void Vector<T>::changeSize(std::size_t newSize)
{
	T* pTemp{ new T[newSize] }; //Get new storage space
	//Copy the correct number of elements
	const std::size_t smallerNumber{ newSize > m_amount ? m_amount : newSize };
	for (std::size_t i = 0; i < smallerNumber; ++i)
		pTemp[i] = m_start[i];
	delete[] m_start; //Release old storage space
	m_start = pTemp; //Update administrative data
	m_amount = newSize;  //Update administrative data
}

