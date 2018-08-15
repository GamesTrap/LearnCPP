#pragma once
#include <ostream>
#include <iostream>

class Rational
{
public:
	Rational(long n = 0, long d = 1); //General constructor

	//Getters
	long getNumerator() const;
	long getDenominator() const;

	//Arithmetic methods for +=, -=, *=, /=,
	//(are later supplemented by overloaded operators)
	void add(Rational r);
	void sub(Rational r);
	void mult(Rational r);
	void div(Rational r);

	//Other methods
	void set(long n, long d);
	void reciprocalValue();
	void reduce();

private:
	long m_numerator, m_denominator;
};

//inline methods
inline Rational::Rational(const long n, const long d) : m_numerator{ n }, m_denominator{ d } {}

inline long Rational::getNumerator() const { return m_numerator; }
inline long Rational::getDenominator() const { return m_denominator; }

//Global function prototypes
Rational add(Rational a, Rational b);
Rational sub(Rational a, Rational b);
Rational mult(Rational a, Rational b);
Rational div(Rational n, Rational d);

void input(Rational& r);
void output(Rational r, std::ostream& = std::cout);