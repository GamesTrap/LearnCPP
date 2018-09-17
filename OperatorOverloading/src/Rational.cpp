#include "Rational.h"

namespace
{
	void checkUnequalNull(long denominator)
	{
		if (denominator == 0)
			throw std::invalid_argument("Denominator cant be null!");
	}

	//Global helper function (Greatest common divider)
	long gcd(long x, long y)
	{
		long rest;

		while(y)
		{
			rest = x % y;
			x = y;
			y = rest;
		}

		return x;
	}
}

//// ****** + Method implementation ********
Rational::Rational(long n, long d)
	: m_numerator{n}, m_denominator{d}
{	
	checkUnequalNull(m_denominator);
	reduce();
}

void Rational::set(long numerator, long denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
	checkUnequalNull(m_denominator);
}

void Rational::reciprocalValue()
{
	long temp = m_numerator;
	m_numerator = m_denominator;
	m_denominator = temp;
	checkUnequalNull(m_denominator);
}

void Rational::reduce()
{
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

	long divisor = gcd(m_numerator, m_denominator);
	m_numerator = sign * m_numerator / divisor;
	m_denominator = m_denominator / divisor;
}

Rational& Rational::operator+=(Rational b)
{
	m_numerator = m_numerator * b.m_denominator + b.m_numerator * m_denominator;
	m_denominator = m_denominator * b.m_denominator;
	reduce();

	return *this;
}

Rational& Rational::operator-=(Rational b)
{
	m_numerator = m_numerator * b.m_denominator - b.m_numerator * m_denominator;
	m_denominator = m_denominator * b.m_denominator;
	reduce();

	return *this;
}

Rational& Rational::operator*=(Rational b)
{
	m_numerator = m_numerator * b.m_numerator;
	m_denominator = m_denominator * b.m_denominator;
	reduce();

	return *this;
}

Rational& Rational::operator/=(Rational b)
{
	b.reciprocalValue();

	m_numerator = m_numerator * b.m_numerator;
	m_denominator = m_denominator * b.m_denominator;
	reduce();

	return *this;
}

//// ******* Global operator +, -, *, / ********
Rational operator+(Rational a, Rational b)
{
	return a += b; //Returning a.operator += (b)
}

Rational operator-(Rational a, Rational b)
{
	return a -= b; //Returning a.operator -= (b)
}

Rational operator*(Rational a, Rational b)
{
	return a *= b; //Returning a.operator *= (b)
}

Rational operator/(Rational a, Rational b)
{
	return a /= b; //Returning a.operator /= (b)
}

// ******* Another global operator
bool operator==(Rational a, Rational b)
{
	return a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator();
}

bool operator!=(Rational a, Rational b)
{
	return a.getNumerator() != b.getNumerator() && a.getDenominator() != b.getDenominator();
}

std::ostream& operator<<(std::ostream& output, Rational r)
{
	output << r.getNumerator() << '/' << r.getDenominator();

	return output;
}

std::istream& operator>>(std::istream& input, Rational& r)
{
	long int n;
	long int d;

	input >> n >> d;
	checkUnequalNull(d);

	r.set(n, d);
	r.reduce();

	return input;
}