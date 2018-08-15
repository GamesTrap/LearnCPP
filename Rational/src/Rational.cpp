#include "Rational.h"

#include <cassert>

namespace
{
	//The function gcd() is needed for reducing.
	//It calculates the greatest common divisor.
	//A modified Euclid algorithm is used, in which subtractions are replaced by the faster residuals.
	long gcd(long x, long y)
	{
		while(y > 0)
		{
			const long rest = x % y;
			x = y;
			y = rest;
		}

		return x;
	}
}

//Member functions
void Rational::add(const Rational r)
{
	m_numerator = m_numerator * r.m_denominator + r.m_numerator * m_denominator;
	m_denominator = m_denominator * r.m_denominator;
	reduce();
}

void Rational::sub(const Rational r)
{
	m_numerator = m_numerator * r.m_denominator - r.m_numerator * m_denominator;
	m_denominator = m_denominator * r.m_denominator;
	reduce();
}
void Rational::mult(const Rational r)
{
	m_numerator = m_numerator * r.m_numerator;
	m_denominator = m_denominator * r.m_denominator;
	reduce();
}
void Rational::div(const Rational r)
{
	m_numerator = m_numerator * r.m_denominator;
	m_denominator = m_denominator * r.m_numerator;
	reduce();
}
void Rational::set(const long n, const long d)
{
	m_numerator = n;
	m_denominator = d;
	assert(m_denominator != 0);
	reduce();
}

void Rational::reciprocalValue()
{
	const long temp = m_numerator;
	m_numerator = m_denominator;
	m_denominator = temp;
	assert(m_denominator != 0);
}

void Rational::reduce()
{
	//Remember sign and make amount
	int sign = 1;

	if(m_numerator < 0)
	{
		sign = -sign;
		m_numerator = -m_numerator;
	}
	if(m_denominator < 0)
	{
		sign = -sign;
		m_denominator = -m_denominator;
	}
	const long divider = gcd(m_numerator, m_denominator);
	m_numerator = sign * m_numerator / divider; //Restore sign
	m_denominator = m_denominator / divider;
}

//Following are the global arithmetic functions for the operations with 2
//parameters (binary operations)
Rational add(Rational a, const Rational b)
{
	//The actual calculation need not be repeated here, but the already
	//existing functions for the short forms of addition, etc.
	//can be advantageously reused.
	//For this purpose, the argument b is added to a that is passed by value
	//and therefore represents a copy.
	//The result is returned.
	a.add(b);
	return a;
}
Rational sub(Rational a, const Rational b)
{
	a.sub(b); //See discussion at add()
	return a;
}
Rational mult(Rational a, const Rational b)
{
	a.mult(b); //See discussion at add()
	return a;
}
Rational div(Rational n, const Rational d)
{
	n.div(d); //See discussion at add()
	return n;
}

//Functions for input and output
void input(Rational& r)
{
	long int n;
	long int d;
	std::cin >> n >> d;
	assert(n != 0);
	r.set(n, d);
	r.reduce();
}

void output(Rational r, std::ostream& os)
{
	os << r.getNumerator() << '/' << r.getDenominator() << '\n';
}