#pragma once

#include <vector>

//Matrix as vector of vectors
template<typename T>
class Matrix : public std::vector<std::vector<T>>
{
public:
	using super = std::vector<std::vector<T>>; //Abbreviation for upper class type

	Matrix(std::size_t r = 1, std::size_t c = 1) //Rows, Columns
	//Initialization with r vectors of length c:
		: std::vector<std::vector<T>>(r, std::vector<T>(c))
	{}

	auto rows() const
	{
		return super::size();
	}

	//The number of columns is the length of one of the vectors (here 0)
	auto columns() const
	{
		return super::operator[](0).size();
	}

	void init(T);

	//Mathematical operators and functions
	Matrix<T>& I(); //Create a unit matrix
	Matrix<T>& operator*=(T);
	Matrix<T>& operator*=(const Matrix<T>&);

	//... additional operators and functions
};

template <typename T>
void Matrix<T>::init(T value)
{
	for (std::size_t i = 0; i < rows(); ++i)
		super::operator[](i)[i] = value;
	//operator[](i) is of type vector<T>
}

template <typename T>
Matrix<T>& Matrix<T>::I() //Unit matrix
{
	for (std::size_t i = 0; i < rows(); ++i)
		for (std::size_t j = 0; j < columns(); ++j)
			super::operator[](i)[j] = (i == j) ? T(1) : T(0);

	return *this;
}

//Multiplication by a number
template <typename T>
Matrix<T>& Matrix<T>::operator*=(T factor)
{
	for (std::size_t i = 0; i < rows(); ++i)
		super::operator[](i) *= factor; //Vector::operator*=()

	return *this;
}

//Multiplication with a matrix
template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& b)
{
	if (columns() != b.rows())
		throw "Wrong dimension in Matrix*= !";
	Matrix<T> res(rows(), b.columns());
	for(std::size_t i = 0; i < rows(); ++i)
		for(std::size_t j = 0; j < b.columns(); ++j)
		{
			res[i][j] = T(0);
			for (std::size_t k = 0; k < columns(); ++k)
				res[i][j] += super::operator[](i)[k] * b[k][j];
		}
	super::swap(res); //Swap *this with erg

	return *this;
}

template<typename T>
Matrix<T> operator*(Matrix<T> a, const Matrix<T>& b)
{
	return a *= b;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Matrix<T>& m)
{
	for(std::size_t i = 0; i < m.rows(); ++i)
	{
		s << '\n' << i << " :  ";
		for (std::size_t j = 0; j < m.columns(); ++j)
			s << m[i][j] << " ";
	}
	s << '\n';

	return s;
}