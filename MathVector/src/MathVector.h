#pragma once

#include "Vector.h"
#include <ostream>

template<typename T>
class MathVector : public Vector<T>
{
public:
	using super = Vector<T>; //Abbreviation for upper class type
	using Vector<T>::Vector; //Inheriting constructors
	void init(T); //Set all elements

	//Operators
	MathVector& operator*=(T); //Operator *=
	//Further operators and functions ...
};

template <typename T>
void MathVector<T>::init(T value)
{
	for (std::size_t i = 0; i < super::size(); ++i)
		super::operator[](i) = value;
}

template <typename T>
MathVector<T>& MathVector<T>::operator*=(T number)
{
	for (std::size_t i = 0; i < super::size(); ++i)
		super::operator[](i) *= number; //Element-wise multiplication

	return *this;
}

//* Operator for the case v1 = number * v2;
template<typename T>
MathVector<T> operator*(T number, MathVector<T> mv)
{
	return mv *= number; //Calling operator * = ()
}

//* Operator for the case v1 = v2 * number;
//(Reversed order of arguments)
template<typename T> 
MathVector<T> operator*(MathVector<T> mv, T number)
{
	return mv *= number; //Calling operator * = ()
}

/*
 *Because MathVector uses only mathematically meaningful data types
 *is instantiated for which the standard output operator is defined
 *it is useful to have an operator for the output of a
 *To define MathVector object:
 */

template<typename T>
std::ostream& operator<<(std::ostream& os, const MathVector<T>& mv)
{
	//Improvements in the output layout are possible!
	for(std::size_t i = 0; i < mv.size(); ++i)
	{
		os << mv[i] << '\t';
		if ((i + 1) % 8 == 0 || i == mv.size() - 1)
			os << '\n';
	}

	return os;
}