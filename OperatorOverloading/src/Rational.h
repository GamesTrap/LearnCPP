#pragma once

#include <iostream>

class Rational
{
public:
	Rational(long n = 0L, long d = 1L); //Replaces type conversion constructor

	//Getters
	long getNumerator() const;
	long getDenominator() const;

	//Arithmetic methods
	Rational& operator+=(Rational);
	Rational& operator-=(Rational);
	Rational& operator*=(Rational);
	Rational& operator/=(Rational);
	//Further arithmetic methods omitted

	//Further methods
	void set(long numerator, long denominator);
	void reciprocalValue();
	void reduce();

private:
	long m_numerator;
	long m_denominator;
};

//inline methods
inline long Rational::getNumerator() const { return m_numerator; }
inline long Rational::getDenominator() const { return m_denominator; }

//Global operator +, -, * and /
Rational operator+(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator*(Rational, Rational);
Rational operator/(Rational, Rational);

//******* Further global operator
bool operator==(Rational, Rational);
bool operator!=(Rational, Rational);

//Global functions for input and output
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);