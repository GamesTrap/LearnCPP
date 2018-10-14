#pragma once

#include "Matrix.h"

template<typename T>
class Matrix3D : public std::vector<Matrix<T>> //3D matrix as vector of 2D matrices
{
public:
	using super = std::vector<Matrix<T>>; //Upper class type

	Matrix3D(std::size_t d1 = 1, std::size_t d2 = 1, std::size_t d3 = 1)
		: std::vector<Matrix<T>>(d1, Matrix<T>(d2, d3))
	{		
	}

	auto dim1() const
	{
		return super::size();
	}
	auto dim2() const
	{
		return super::operator[](0).size();
	}
	auto dim3() const
	{
		return super::operator[](0).operator[](0).size();
	}

	void init(T); //Initialization
	Matrix3D<T>& I(); //Unit matrix

	//Mathematical operators 
	Matrix3D<T>& operator*=(T); //Multiplication
	//Additional operators and functions ...
};

template <typename T>
void Matrix3D<T>::init(T value) //Initialization
{
	for (std::size_t i = 0; i < dim1(); ++i)
		super::operator[](i).init(value); //Matrix<T>::operator[](i)
}


template <typename T>
Matrix3D<T>& Matrix3D<T>::I() //Unit matrix
{
	for (std::size_t i = 0; i < dim1(); ++i)
		super::operator[](i).I();

	return *this;
}

template <typename T>
Matrix3D<T>& Matrix3D<T>::operator*=(T factor)
{
	for (std::size_t i = 0; i < dim1(); ++i)
		super::operator[](i) *= factor; //Matrix::operator*=()

	return *this;
}